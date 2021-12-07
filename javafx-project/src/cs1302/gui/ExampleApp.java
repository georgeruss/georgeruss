package cs1302.gui;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import javafx.scene.control.Button;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;

/**
 * Represents a small example app written using JavaFX.
 */
public class ExampleApp extends Application {

    /** {@inheritDoc} */
    @Override
    public void start(Stage stage) {

        Text hello = new Text("Hello World!!!");

        Button button = new Button("Click me!");
        EventHandler<ActionEvent> buttonHandler = event -> System.out.println("you clicked me!");
        HBox root = new HBox();
        button.setOnAction(buttonHandler);
        root.getChildren().add(button);
        root.getChildren().add(hello);

        Scene scene = new Scene(root);

        stage.setScene(scene);
        stage.sizeToScene();
        stage.setTitle("ExampleApp!");
        stage.show();

    } // start
} // ExampleApp
