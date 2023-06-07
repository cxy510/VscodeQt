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

// 压缩与解压文件夹
void ZipTool::compress(QString target_name,QString source_path){
    JlCompress::compressDir(target_name,source_path);
    
}

void ZipTool::unCompress(QString zip_path,QString target_path){    
    JlCompress::extractDir(zip_path,target_path);
}
 