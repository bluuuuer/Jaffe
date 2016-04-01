// huangshize 2016.03.30
// === io.hpp ===
// 提供用于解决数据输入输出的方法
#include "io.h"


bool ReadFileToDatum(const string& filename, const int label, JDatum* datum)
{
	streampos size;
	fstream file(filename.c_str(), ios::in | ios::binary | ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		string buffer(size, ' ');
		file.seekg(0, ios::beg);
		file.read(&buffer[0], size);
		file.close();
		datum->SetData(buffer);
		datum->SetLabel(label);
		datum->SetEncoded(true);
		return true;
	}
	else
	{
		return false;
	}
}
//  参考caffe，该方法用于读图并返回一个Mat数据
cv::Mat ReadImageToCVMat(const string& filename, const int height = 0, const int width = 0, const bool is_color = 1)
{
	cv::Mat cv_img;
	int cv_read_flag = (is_color ? CV_LOAD_IMAGE_COLOR : CV_LOAD_IMAGE_GRAYSCALE);
	cv::Mat cv_img_origin = cv::imread(filename, cv_read_flag);
	// if(!cv_img_origin.data)
	if (height > 0 && width > 0)
	{
		cv::resize(cv_img_origin, cv_img, cv::Size(width, height));
	}
	else
	{
		cv_img = cv_img_origin; 
	}
	return cv_img;
}

void CVMatToDatum(const cv::Mat& cv_img, JDatum* datum)
{
	// 图像的数据类型必须是未编码的
	datum->SetChannels(cv_img.channels());
	datum->SetHeight(cv_img.rows);
	datum->SetWidth(cv_img.cols);
	
	int datum_channels = datum->GetChannels();
	int datum_height = datum->GetHeight();
	int datum_width = datum->GetWidth();
	long datum_size = datum_channels * datum_height * datum_width;

	string buffer(datum_size, ' ');
	for (int h = 0; h < datum_height; ++h)
	{
		const uchar* ptr = cv_img.ptr<uchar>(h);
		int img_index = 0;
		for (int w = 0; w < datum_width; ++w)
		{
			for (int c = 0; c < datum_channels; ++c)
			{
				int datum_index = (c * datum_height + h) * datum_width + w;
				buffer[datum_index] = static_cast<char>(ptr[img_index++]);

			}
		}
	}
	datum->SetData(buffer);
}
static bool matchExt(const string& fn, string en)
{
	size_t p = fn.rfind('.');
	string ext = p != fn.npos ? fn.substr(p) : fn;
	transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
	transform(en.begin(), en.end(), en.begin(), ::tolower);
	if ((ext == en) || (en == "jpg" && ext == "jpeg") )
	{
		return true;
	}
	return false;

}

bool ReadImageToDatum(const string& filename, const int label, const int height, const int width,
	const bool is_color, const string& encoding, JDatum* datum)
{
	cv::Mat cv_img = ReadImageToCVMat(filename, height, width, is_color);
	if (cv_img.data)
	{
		if (encoding.size())
		{
			if ((cv_img.channels() == 3) && is_color == 1 && !height && !width && matchExt(filename, encoding))
			{
				return ReadFileToDatum(filename, label, datum);
			}
			vector<uchar> buf;
			cv::imencode("." + encoding, cv_img, buf);
			datum->SetData(string(reinterpret_cast<char*>(&buf[0]), buf.size()));
			datum->SetLabel(label);
			datum->SetEncoded(true);
			return true;
		}
		CVMatToDatum(cv_img, datum);
		datum->SetLabel(label);
		return true;
	} 
	else
	{
		return false;
	}
}

void PutDatumToDataset(JDatum* datum, const string& db_backend)
{

}