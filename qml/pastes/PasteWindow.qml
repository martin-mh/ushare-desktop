import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import Material 0.1
import Material.ListItems 0.1

ApplicationWindow
{
    id: root;
    title: qsTr('Cook a new paste');

    initialPage: page;

    signal send(string name, string content);
    signal cancel();

    Page
    {
        id: page;

        title: qsTr('Cook a new paste');

        View
        {
            id: mainView;
            elevation: 1;

            anchors
            {
                fill: parent;
                margins: Units.dp(16);
            }

            Column
            {
                id: column;

                spacing: Units.dp(16);

                anchors
                {
                    fill: parent;
                    margins: Units.dp(16);
                }

                Item
                {
                    anchors
                    {
                        left: parent.left;
                        right: parent.right;
                    }

                    height: buttonSend.height;

                    TextField
                    {
                       id: pasteName;
                       placeholderText: qsTr('Paste name');
                       onTextChanged: text ? page.title = text : page.title = qsTr('Cook a new paste');
                    }


                    Row
                    {
                        spacing: Units.dp(8);
                        anchors.right: parent.right;

                        Button
                        {
                            id: buttonSend;
                            text: qsTr('Send!');
                            elevation: 1;

                            onClicked: root.send(pasteName.text, content.text);
                        }

                        Button
                        {
                            id: buttonCancel;
                            text: qsTr('Cancel');
                            elevation: 1;

                            onClicked: root.cancel();
                        }
                    }
                }


                TextArea
                {
                    id: content;
                    height: mainView.height - y - Units.dp(24);

                    anchors
                    {
                        left: parent.left;
                        right: parent.right;

                    }

                    wrapMode: TextEdit.Wrap;
                }
            }
        }
    }
}