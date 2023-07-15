import QtQuick 2.9  //向下兼容到5.9
import "myscript.js" as Logic
Item {
    id: container
    width: 320
    height: 480

    function randomNumber() {
        return Math.random() * 360;
    }

    function getNumber() {
        return container.randomNumber();
    }

    //TapHandler {
        // This line uses the JS function from the item
      //  onTapped: rectangle.rotation = container.getNumber();
   // }

    Rectangle {
        color: "#272822"
        width: 320
        height: 480
    }

    Rectangle {
        id: rectangle
        anchors.centerIn: parent
        width: 160
        height: 160
        color: "green"
        Behavior on rotation { RotationAnimation { direction: RotationAnimation.Clockwise } }
    }

}

