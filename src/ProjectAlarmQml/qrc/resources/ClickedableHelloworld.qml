import QtQuick 2  //向下兼容到5.9
import QtQuick.Window 2   //顶级窗口
Window{
    visible:true;
    Rectangle {
        width: 200
        height: 100
        color: "red"

        Text {
            anchors.centerIn: parent
            text: "Hello, World!"
        }

        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_Return) {
                color = "blue";
                event.accepted = true;
            }
        }
    }
}
