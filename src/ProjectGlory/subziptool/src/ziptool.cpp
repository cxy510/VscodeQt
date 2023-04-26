/**
 *  @file      ZipTool.cpp
 *  @brief     压缩
 *  @author    cxy(wuyuming510@139.com)
 *  @date      2023-1-16
 *  @copyright 
 */
#include "ziptool.h"

ZipTool::ZipTool(){

}
ZipTool::~ZipTool(){

}

void ZipTool::compress(QString target_name,QString source_path){
    JlCompress::compressDir(target_name,source_path);
}
