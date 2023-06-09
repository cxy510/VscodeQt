/**
 *  @file      ZipTool.h
 *  @brief     压缩
 *  @author    cxy(wuyuming510@139.com)
 *  @date      2023-1-16
 *  @copyright 
 */

#ifndef __SUB_ZIP_TOOL_H__
#define __SUB_ZIP_TOOL_H__

#include <QString>
#include "JlCompress.h"

class ZipTool
{
public:
    ZipTool();
    ~ZipTool();
    void compressDir(QString target_name,QString source_path);
    void unCompressDir(QString zip_path,QString target_path);

    // 压缩单个文件
    bool compressSignalFile(QString file_name,QString file_path,QString zip_name);
    // 从压缩包中，逐个文件解压
    bool uncompressSignalFile(QString zip_name,QString dest_path);
    /**
     压缩
    参数一OutEncodeData：压缩后的数据，返回值QByteArray
    参数二InRawData：待压缩的数据
    参数三nErrorCode：返回故障码
    **/
    long compressData(QByteArray &OutEncodeData,QByteArray InRawData, int *nErrorCode);
    /**
    解压缩
    参数一OutEncodeData：解压缩后的数据，返回值QByteArray
    参数二InRawData：待解压缩的数据
    参数三nErrorCode：返回值故障码
    **/
    long uncompressData(QByteArray &OutDecodeData,QByteArray InEncodeData,int *nErrorCode);
private:
    // 根据长度获取长度
    int  ZlibGetDecodeLength(uLong  InRawLength);

    // 根据QByteArray获取压缩解压缩长度
    int  ZlibGetDecodeLength(QByteArray  InRawData);
   
};




#endif
