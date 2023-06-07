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
    void compress(QString target_name,QString source_path);
    void unCompress(QString zip_path,QString target_path);
};




#endif
