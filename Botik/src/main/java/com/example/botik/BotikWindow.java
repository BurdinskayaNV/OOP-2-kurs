package com.example.botik;

import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class BotikWindow {
    public BotikWindow(String userName) throws IOException {

        FXMLLoader fxmlLoader = new FXMLLoader(BotikWindow.class.getResource("chatik-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
        Stage stage = new Stage();

        BotikWindowController controllerEditBook = fxmlLoader.getController();
        stage.setTitle("Чат-бот с " + userName);
        stage.setScene(scene);
        stage.show();

        controllerEditBook.CountMessages = controllerEditBook.OpenDialogFromFile(controllerEditBook.ArrayMessages, controllerEditBook.CountMessages,userName);
        controllerEditBook.UserName = userName;
        stage.setOnCloseRequest(controllerEditBook.getCloseEventHandler());

    }
}