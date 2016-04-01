// huangshize

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>

#include "common.h"

bool ReadFileToDatum(const string& filename, const int label, JDatum* datum);
//  参考caffe，该方法用于读图并返回一个Mat数据
cv::Mat ReadImageToCVMat(const string& filename, const int height = 0, const int width = 0, const bool is_color = 1);

void CVMatToDatum(const cv::Mat& cv_img, JDatum* datum);

static bool matchExt(const string& fn, string en);

bool ReadImageToDatum(const string& filename, const int label, const int height, const int width, const bool is_color,
	const string& encoding, JDatum* datum);

// hsz encoded默认是空串
inline bool ReadImageToDatum(const string& filename, const int label,
	const int height, const int width, const bool is_color, JDatum* datum) {
	return ReadImageToDatum(filename, label, height, width, is_color,
		"", datum);
}

inline bool ReadImageToDatum(const string& filename, const int label,
	const int height, const int width, JDatum* datum) {
	return ReadImageToDatum(filename, label, height, width, true, datum);
}

inline bool ReadImageToDatum(const string& filename, const int label,
	const bool is_color, JDatum* datum) {
	return ReadImageToDatum(filename, label, 0, 0, is_color, datum);
}

inline bool ReadImageToDatum(const string& filename, const int label,
	JDatum* datum) {
	return ReadImageToDatum(filename, label, 0, 0, true, datum);
}

inline bool ReadImageToDatum(const string& filename, const int label,
	const std::string & encoding, JDatum* datum) {
	return ReadImageToDatum(filename, label, 0, 0, true, encoding, datum);
}

void PutDatumToDataset(JDatum* datum, const string& db_backend);