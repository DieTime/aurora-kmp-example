import QtQuick 2.0
import Sailfish.Silica 1.0
import Shared 1.0

Page {
    Greeting {
        id: greeting
    }

    GithubRepository {
        id: github
    }

    Column {
        anchors.centerIn: parent

        Label {
            text: greeting.greet()
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: Theme.fontSizeLarge
            color: Theme.primaryColor
        }

        Label {
            text: "Revision: " + github.revision.slice(0, 8)
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: Theme.fontSizeLarge
            color: Theme.primaryColor
        }
    }
}