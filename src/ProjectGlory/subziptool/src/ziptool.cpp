#include "ziptool.h"

ZipTool::ZipTool(){

}
ZipTool::~ZipTool(){

}

void ZipTool::compress(QString target_name,QString source_path){
    JlCompress::compressDir(target_name,source_path);
}
