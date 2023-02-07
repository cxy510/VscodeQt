#include "TableViewPrint.h"

TableViewPrint::TableViewPrint(QTableView *tableview){
    tableview_=tableview;
    initModel();
}

TableViewPrint::~TableViewPrint(){

}

void TableViewPrint::initModel(){
    model_->setColumnCount(col_num_);
    tableview_->setSelectionBehavior(QAbstractItemView::SelectRows);// 整行选择
    tableview_->horizontalHeader()->setStretchLastSection(true);// 最后一列
    tableview_->setModel(model_);// 设置列表的数据类型   
    tableview_->setEditTriggers(QAbstractItemView::NoEditTriggers);// 设置不可编辑
   
}

void TableViewPrint::insertData(QStringList stringlist){
    model_->insertRow(0);
    setRowData(0,stringlist);
}

void TableViewPrint::setRowData(int row,QStringList stringlist){
    model_->setItem(row,0,new QStandardItem(stringlist[0]));
}
