#include "TableViewBase.h"

TableViewBase::TableViewBase(QTableView *tableview,QAbstractTableModel *model):tableview_(tableview),model_(model){ 
    initModel();
}

TableViewBase::~TableViewBase(){
    if (model_!=NULL) {
        delete model_;
        model_=NULL;
    }
    
}

void TableViewBase::initModel(){      
    tableview_->setSelectionBehavior(QAbstractItemView::SelectRows);// 整行选择
    tableview_->horizontalHeader()->setStretchLastSection(true);// 最后一列
    tableview_->setModel(model_);// 设置列表的数据类型   
    tableview_->setEditTriggers(QAbstractItemView::NoEditTriggers);// 设置不可编辑
   
}

// void TableViewPrint::insertData(QStringList stringlist){
//     model_->insertRow(0);
//     setRowData(0,stringlist);
// }

// void TableViewPrint::setRowData(int row,QStringList stringlist){
//     model_->setItem(row,0,new QStandardItem(stringlist[0]));
// }
