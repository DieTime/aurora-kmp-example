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

    Database {
        id: database

        onRecordCurrentVisitCompleted: {
            updateLastVisits()
        }

        Component.onCompleted: {
            database.recordCurrentVisit()
        }
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

        Label {
            id: lastVisitsLabel
            text: "Last visits:"
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: Theme.fontSizeLarge
            color: Theme.primaryColor
        }

        SilicaListView {
            width: parent.width
            height: contentHeight
            model: database.lastVisits
            delegate: Label {
                width: ListView.view.width
                height: lastVisitsLabel.height
                Label {
                    anchors.centerIn: parent
                    text: modelData
                }
            }
        }
    }
}