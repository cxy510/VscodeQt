/**
 *  @file      ZipTool.cpp
 *  @brief     压缩
 *  @author    cxy(wuyuming510@139.com)
 *  @date      2023-1-16
 *  @copyright 
 */
#include "ziptool.h"
#include <QDebug>

ZipTool::ZipTool(){

}
ZipTool::~ZipTool(){

}

bool ZipTool::compressSignalFile(QString file_name,QString file_path,QString zip_name){
    QuaZip zip(zip_name);
    // 如果存在，创建
    QFile file_zip(zip_name);
    if (!file_zip.exists())
    {// 如果不存在，追加
         qDebug()<<"create result:"<<zip.open(QuaZip::mdCreate);        
    }else{
         qDebug()<<"add result:"<<zip.open(QuaZip::mdAdd);       
    }     
    
    
    qDebug()<<"compress result"<<JlCompress::compressFile(&zip, file_path,file_name);
    //qDebug()<<"compress result"<<JlCompress::compressFile(&zip, zip_name,file_name);
    //return JlCompress::compressFile(zip_name, file_name);
    zip.close();
    return true;
}

// 从压缩包中，逐个文件解压
bool ZipTool::uncompressSignalFile(QString zip_name,QString dest_path){
    QStringList file_list=JlCompress::getFileList(zip_name);
    foreach(auto var,file_list){
        qDebug()<<"file name:"<<var<<"  file path:"<<dest_path;
        qDebug()<<"extract file:"<<JlCompress:: extractFile(zip_name,var,dest_path+"/"+var);
    }
}

// 压缩与解压文件夹
void ZipTool::compressDir(QString target_name,QString source_path){
    JlCompress::compressDir(target_name,source_path);
    
}

void ZipTool::unCompressDir(QString zip_path,QString target_path){    
    JlCompress::extractDir(zip_path,target_path);
}
 
 
/*
 * 函  数: ZlibGetDecodeLength
 * 功  能: 通过要压缩的数据大小，得到压缩后数据的最大大小
 *        以此设置缓冲区
 * 参  数: uLong  InRawLength  压缩前数据大小
 */
 
int  ZipTool::ZlibGetDecodeLength(uLong  InRawLength)
{
    return  compressBound(InRawLength);
}
 
/*
 * 函  数: ZlibGetDecodeLength
 * 功  能: 通过要压缩的数据大小，得到压缩后数据的最大大小
 *        以此设置缓冲区
 * 参  数: QByteArray  InRawData  压缩前数据
 *
 */
int  ZipTool::ZlibGetDecodeLength(QByteArray  InRawData)
{
    // 注:
    // ((QByteArray)"Hello").size() == 5
    // 因为当字符串为 QByteArray , '\0' 被忽略
    return  compressBound(InRawData.length());
}
 

 
/*
 * 函  数: ZlibCompress
 * 功  能: 执行压缩操作
 * 参  数: QByteArray  &OutEncodeData  压缩后数据
 *        QByteArray  InRawData       要压缩的数据
          int       * nErrorCode      错误代码
 * 说  明: 当 nErrorCode 不为 NULL 时, 若 compress 出错后, 其数据改为
 *          compress 返回的错误代码. 在 zlib.h 中可以找到.
 *        例如: -5  缓冲区长度不够
 * 返回值: 类型 long
 *        返回压缩后的长度, -1 表示压缩失败, 请检查 *nErrorCode .
 */
 
long  ZipTool::compressData(QByteArray  &OutEncodeData, QByteArray  InRawData,
                  int  * nErrorCode = NULL)
{
    Bytef  *EncodeData = NULL;  // 压缩后的数据暂存于此
    int     nFuncRet = Z_ERRNO; // 随便找个错误代码先填着
    long    nOutLength = 0;
    // 申请最大缓冲区
    nOutLength = ZlibGetDecodeLength(InRawData.length());
    EncodeData = new Bytef[nOutLength];
    if (NULL != EncodeData)
    {
        // 调用 compress 函数前, nOutLength 要置为缓冲区大小
        nFuncRet = compress(EncodeData, (uLongf *)&nOutLength, (Bytef *)InRawData.data(),
                            InRawData.length());
 
        if (Z_OK == nFuncRet)
        {
            // 自己设置好长度为好, 省的 '\0' 被截断了
            OutEncodeData.append((const char *)EncodeData, nOutLength);
        }
        else
        {
            nOutLength = -1;
        }
    }
    delete  EncodeData;
 
    // 输出错误代码
    if (NULL != nErrorCode)
    {
        *nErrorCode = nFuncRet;
    }
    return  nOutLength;
}

/*
 * 函  数: ZlibUnCompress
 * 功  能: 执行解压操作
 * 参  数: QByteArray  &OutDecodeData  解压后数据
 *        QByteArray  InEncodeData    要解压的数据
          int       * nErrorCode      错误代码
 * 说  明: 当 nErrorCode 不为 NULL 时, 若 uncompress 出错后, 其数据改为
 *          uncompress 返回的错误代码. 在 zlib.h 中可以找到.
 *        例如: -5  缓冲区长度不够
 * 返回值: 类型 long
 *        返回解压后的长度, -1 表示解压失败, 请检查 *nErrorCode .
 */
 
long  ZipTool::uncompressData(QByteArray  &OutDecodeData, QByteArray InEncodeData,
                     int   * nErrorCode = NULL)
{
    Bytef  *DecodeData = NULL; // 解压后的数据缓冲区
    Bytef  *EncodeData_Buffer = NULL;  // 要解压的数据缓冲区, 后面用memcpy放到这
    int     nFuncRet = Z_ERRNO;
    uLongf  nOutLength = 0;
 
    // 说明:
    // 如果压缩后大小比之前小, 缓冲区大小应该设置多少?
    // 暂且把 ZlibGetDecodeLength 拿来用用, 确保缓冲区够了.
    //nOutLength = ZlibGetDecodeLength(InEncodeData.length());
    nOutLength = InEncodeData.length()*4;   //
    qDebug()<<"InEncodeData.length"<<InEncodeData.length();
    qDebug()<<"nOutLength"<<nOutLength;
 
    // 为缓冲区申请内存
    DecodeData        =  new Bytef[nOutLength];
    EncodeData_Buffer =  new Bytef[nOutLength];
 
    if (NULL != DecodeData && NULL != EncodeData_Buffer)
    {
        // 由于 QByteArray 在 data() 函数中会因为'\0'截断
        // (先鄙视一下，那还叫什么字节操作)
        // 文档又说，constData() 效率高
        // 所以用 constData() 获取地址然后 memcpy 自己复制
        memcpy(EncodeData_Buffer, InEncodeData.constData(), InEncodeData.size());
 
        nFuncRet = uncompress(DecodeData, &nOutLength, (Bytef *)EncodeData_Buffer,
                              InEncodeData.length());
        qDebug()<<"nFuncRet"<<nFuncRet;
        if (Z_OK == nFuncRet)
        {
            OutDecodeData.append((const char *)DecodeData, nOutLength);
        }
        else
        {
            nOutLength = -1;
        }
    }
    else
    {
        nOutLength = -1;
    }
 
    // 清理 new 产生的内存
    if (NULL != DecodeData)
    {
        delete  DecodeData;
    }
 
    if (NULL != EncodeData_Buffer)
    {
        delete  EncodeData_Buffer;
    }
 
    // 输出错误代码
    if (NULL != nErrorCode)
    {
        *nErrorCode = nFuncRet;
    }
    return  nOutLength;
 
}