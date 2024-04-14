module com.example.botik {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.botik to javafx.fxml;
    exports com.example.botik;
}