package cs1302.game;

import cs1302.game.MinesweeperGame;
import java.util.Scanner;
import java.io.File;
import java.util.*;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.lang.ArrayIndexOutOfBoundsException;

/**
 * Main constructor for the MinesweeperDriver
 * class.
 */
public class MinesweeperDriver {

    /**
     * The main method where standard input is given by the user of the program
     * and interpreted. Input from here dictates how the program will
     * be set-up as well as played.
     *
     * @param args is used for the seedfile input
     * to set up the game
     */
    public static void main(String[] args) {

        try {

            String seedPath = args[0];

            Scanner stdIn = new Scanner(System.in);

            MinesweeperGame mg = new MinesweeperGame(stdIn, seedPath);

            mg.play();

        } catch (FileNotFoundException e) {
            System.err.println("File not found:" + e.getMessage());
        } catch (NoSuchElementException nsee) {
            System.err.println("No more lines.");
        }

    }
} // MinesweeperDriver
