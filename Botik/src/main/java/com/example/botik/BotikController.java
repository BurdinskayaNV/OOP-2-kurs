package com.example.botik;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class BotikController {
    @FXML
    public VBox Start;
    private TextField TextFieldUserName;

    @FXML
    public void onHelloButtonClick(ActionEvent actionEvent) {
        try {
           // new BotikWindow(getTextFieldUserName().getText());

            FXMLLoader fxmlLoader = new FXMLLoader(BotikController.class.getResource("chatik-view.fxml"));
            Scene scene = new Scene(fxmlLoader.load(), 1000, 750);
            Stage stage = new Stage();

          //  BotikWindowController controllerEditBook = fxmlLoader.getController();
            stage.setTitle("Чат-бот с ");
            stage.setScene(scene);
            stage.show();


            Start.getScene().getWindow().hide();
        }
        catch (Exception e) { e.printStackTrace(); }
    }

    public TextField getTextFieldUserName() {
        return TextFieldUserName;
    }

    public void setTextFieldUserName(TextField textFieldUserName) {
        TextFieldUserName = textFieldUserName;
    }
    //protected void onHelloButtonClick() {
    //    welcomeText.setText("Welcome to JavaFX Application!");    }
}