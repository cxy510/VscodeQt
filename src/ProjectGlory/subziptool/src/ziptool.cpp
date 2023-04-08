#include "ziptool.h"

ZipTool::ZipTool(){

}
ZipTool::~ZipTool(){

}

void ZipTool::compress(QString target_name,QString source_path){
    JlCompress::compressDir("E:\\20230107.zip","E:\\2023-01-07");
}
