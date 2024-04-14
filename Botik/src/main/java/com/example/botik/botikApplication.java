package com.example.botik;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
//import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.io.IOException;

public class botikApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(botikApplication.class.getResource("botik-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 1050, 750);
        stage.setTitle("Чат-бот!");
        //boolean add = stage.getIcons().add(new Image("/chat.png"));
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}