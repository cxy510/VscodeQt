// 连接各个qml文件
import QtQuick 2  //向下兼容到5.9
import QtQuick.Window 2   //顶级窗口
import "myscript.js" as Script

// Window {     //注册到Qt quick的对象
//     visible: true
//     width: 640
//     height: 480
//     title: qsTr("Hello World")

//     Rectangle{
//            width: parent.width/2
//            height: parent.height/2    //widget&height是Rectangle的对象
//            color: "red"
//            Text {    //Text可以通过Rectangle对象的子对象输出文本
//                id: title
//                text: qsTr("hello world")
//            }
//        }

// }


Window {
    visible: true
    width: 320
    height: 480

    Rectangle {
        color: "white"
        width: 320
        height: 480
    }

    // This element displays a rectangle with a gradient and a border
    Rectangle {
        x: 160
        y: 20
        width: 100
        height: 100
        radius: 8 // This gives rounded corners to the Rectangle
        gradient: Gradient { // This sets a vertical gradient fill
            GradientStop { position: 0.0; color: "aqua" }
            GradientStop { position: 1.0; color: "teal" }
        }
        border { width: 3; color: "white" } // This sets a 3px wide black border to be drawn
    }

    // This rectangle is a plain color with no border
    Rectangle {
        x: 40
        y: 20
        width: 100
        height: 100
        color: "red"
        // This element displays an image. Because the source is online, it may take some time to fetch      
    }

    Rectangle {
        x: 40
        y: 160
        width: Script.calculateWidth(parent);
        height: 100
        color: "blue"
        // width: {
        //     var w = parent.width / 3
        //     console.debug(w)
        //     return w
        // }
    }   

    MouseArea {
        anchors.fill: parent
        onClicked: {
            var scenePos = mapToItem(null, mouseX, mouseY);
            console.log("MouseArea was clicked at scene pos " + scenePos);
        }
    }

  
}


