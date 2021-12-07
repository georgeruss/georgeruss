package cs1302.game;

import java.util.Scanner;
import java.io.*;

/**
 * Start of MinesweeperGame class.
 */
public class MinesweeperGame {
    private final Scanner stdIn;

    private int rows = 0;
    private int columns = 0;
    private int bombL1;
    private int bombL2;
    private int mineAmount = 0;
    private int roundsCompleted = 0;
    private String[][] noFogArray;
    private String[][] minesweeperArray;
    private boolean[][] isMineArray;

    /**
     * Constructor for the MinesweeperGame class.
     *
     * @param stdIn receives input for commands
     * @param seedPath receives input for the game setup
     */
    public MinesweeperGame(Scanner stdIn, String seedPath)throws FileNotFoundException {
        this.stdIn = stdIn;
        File file = new File(seedPath);
        Scanner sc = new Scanner(file);
        if (sc.hasNextInt()) {
            rows = sc.nextInt();
            if (sc.hasNextInt()) {
                columns = sc.nextInt();
                if (sc.hasNextInt()) {
                    mineAmount = sc.nextInt();
                    if (mineAmount < 1) {
                        System.out.println("The amount of bombs is less than accepted.");
                        System.exit(0);
                    }
                    int x = 0;
                    while (x < mineAmount) {
                        if (sc.hasNextInt()) {
                            minesweeperArray = new String[rows][columns];
                            isMineArray = new boolean[rows][columns];
                            setTheField();
                            for (int y = 0; y < mineAmount; y++) {
                                int i = sc.nextInt();
                                if (i >= rows || i >= columns) {
                                    System.out.println();
                                    System.err.print("Seed File Malformed Error: " +
                                                     "Cannot create a mine field with " +
                                                      "that many rows and/or columns.");
                                    System.out.println();
                                    System.exit(0);
                                } else {
                                    bombL1 = i;
                                }
                                if (sc.hasNextInt()) {
                                    int j = sc.nextInt();
                                    if (j >= rows || j >= columns) {
                                        System.out.println();
                                        System.err.print("Seed File Malformed Error: " +
                                                         "Cannot create a mine field with " +
                                                         "that many rows and/or columns.");
                                        System.out.println();
                                        System.exit(0);
                                    } else {
                                        bombL2 = j;
                                        isMineArray[bombL1][bombL2] = true;
                                    }
                                }
                                x++;
                            }
                        }
                    }

                }
            }


        } else {
            System.out.println("Cannot create game with this seed.");
            System.exit(0);
        }
    } // MinesweeperGame

    /**
     * Prints {@code printWelcome} to standard output.
     */
    public void printWelcome() {

        System.out.println("         _");
        System.out.println("   /\\/\\ (F)_ __   ___  _____      _____  ___ _ __   ___ _ __");
        System.out.println("  /    \\| | '_ \\ / _ \\/ __\\ \\" +
                           " /\\ / / _ \\/ _ \\ '_ \\ / _ \\ '__|");
        System.out.println(" / /\\/\\ \\ | | | |  __/\\__ \\\\ V  V /  __/  __/ |_) |  __/ | ");
        System.out.println(" \\/    \\/_|_| |_|\\___||___/ \\_/\\_/ \\___|\\___| .__/ \\___|_| ");
        System.out.println("                              ALPHA EDITION |_| v2021.sp");
    } // printWelcome

    /**
     * This method {@code setTheField} sets the
     * mine field to blankspaces.
     */
    public void setTheField() {
        for (int i = 0; i < minesweeperArray.length; i++) {
            for (int j = 0; j < minesweeperArray[i].length; j++) {
                minesweeperArray[i][j] = "  ";
            }
        }
    }

    /**
     * Prints {@code printMineField} the minefield grid to standard output.
     */
    public void printMineField() {

        for (int x = 0; x < minesweeperArray.length; x++) {
            if (x < 10) {
                System.out.print(" " + x + " |");
            } else {
                System.out.print(" " + x + "|");
            }
            for (int y = 0; y < minesweeperArray[x].length; y++) {
                if (minesweeperArray[x][y] != null) {
                    if (minesweeperArray[x][y] != "< >" && minesweeperArray[x][y] != "<F>"
                        && minesweeperArray[x][y] != "<?>") {
                        System.out.print(minesweeperArray[x][y]);
                        System.out.print(" ");
                    } else if (minesweeperArray[x][y] == "< >" || minesweeperArray[x][y] == "<F>"
                              || minesweeperArray[x][y] == "<?>") {
                        System.out.print(minesweeperArray[x][y]);
                    }
                }
                if (y < minesweeperArray[x].length - 1) {
                    System.out.print("|");
                }
            }
            System.out.println("|");
        }
        System.out.print("    ");
        for (int i = 0; i < minesweeperArray[0].length; i++) {
            System.out.print( " " + i + "  ");
        }
        System.out.println();
    } // printMineField

    /**
     * This method prompts the user for input
     * to decide the next move.
     */
    public void promptUser() {
        printInputLine();
        String input = stdIn.nextLine().trim();
        Scanner sc = new Scanner(input);
        String cases = sc.next().trim();
        switch (cases) {
        case "h":
            help();
            break;
        case "help":
            help();
            break;
        case "q":
            quit();
            break;
        case "quit":
            quit();
            break;
        case "g":
        case "guess":
            if (!guess(sc)) {

                commandNotRecognized();
            }
            if (guess(sc)) {
                roundsCompleted++;
                guess(sc);
            }
            break;
        case "m":
        case "mark":
            if (!mark(sc)) {

                commandNotRecognized();
            }
            if (mark(sc)) {
                //roundsCompleted++;
                mark(sc);
            }
            break;
        case "r":
        case "reveal":
            if (!reveal(sc)) {
                commandNotRecognized();
            }
            if (reveal(sc)) {
                //roundsCompleted++;
                reveal(sc);
            }
            break;
        case "nofog":
            roundsCompleted++;
            noFog(sc);
            break;
        default:
            commandNotRecognized();
        }
    } // promptUser

    /**
     * This method prints how many rounds have been completed so far.
     */
    private void printRoundsCompleted() {

        System.out.println(" Rounds Completed: " + roundsCompleted);
        System.out.println();
    } // printRoundsCompleted

    /**
     * This method the number of adjacent mines within the vicinity of
     * the grid selection.
     *
     * @return the amount of mines in an area
     * @param row provides data for the amount of mines
     * @param  col provides data for the amount of mines
     */
    private int getNumAdjMines(int row, int col) {
        int numOfAdjMines = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            if (!(i >= 0 && i < minesweeperArray.length)) {
                continue;
            }
            for (int j = col - 1; j <= col + 1; j++) {
                if ((i == row && j == col) || (!(j >= 0 && j < minesweeperArray[0].length))) {
                    continue;
                } else {
                    if (isMineArray[i][j]) {
                        numOfAdjMines++;
                    }
                }
            }
        }
        return numOfAdjMines;
    } // getNumAdjMines

    /**
     * This method determines if the player "won" or not.
     *
     * @return true if win conditions are met
     */
    public boolean isWon() {

        boolean squaresRevealed = false;
        boolean minesFound = false;
        int r = 0;
        int z = 0;

        for (int x  = 0; x  < minesweeperArray.length; x++) {
            for (int y = 0; y < minesweeperArray[x].length; y++) {
                if (isMineArray[x][y] == true) {
                    if (minesweeperArray[x][y] == " F" || minesweeperArray[x][y] == "<F>" ) {
                        minesFound = true;
                    }
                } else {
                    if (isMineArray[x][y] == false) {
                        /**if (minesweeperArray[rows - 1][columns - 1] != null) {
                           if ( minesweeperArray[rows - 1][columns - 1] == " ?") {
                            squaresRevealed = true;
                            } else if (minesweeperArray[rows - 1][columns - 1] != " ?") {
                            squaresRevealed = true;
                            }
                            }*/
                        if (minesweeperArray[x][y] != "  " &&  minesweeperArray[x][y] != " F"
                            && minesweeperArray[x][y] != " ?") {
                            squaresRevealed = true;
                        } else {
                            squaresRevealed = false;
                        }
                    }
                }
            }
        }

        return squaresRevealed && minesFound;
    } // isWon

    /**
     * This method allows a view of the mines present on the board
     * at any given moment.
     *
     * @param stdIn receives input from the standard input to call on method
     * @return true if noFog is completed
     */
    public boolean noFog(Scanner stdIn) {
        boolean completedNoFog = false;
        for (int i = 0; i < isMineArray.length; i++) {
            for (int e = 0; e < isMineArray[i].length; e++) {
                if (isMineArray[i][e] == true) {
                    if (minesweeperArray[i][e] == " F") {
                        minesweeperArray[i][e] = "<F>";
                    } else if (minesweeperArray[i][e] == " ?") {
                        minesweeperArray[i][e] = "<?>";
                    } else if (minesweeperArray[i][e] == "< >") {
                        minesweeperArray[i][e] = null;
                    } else {
                        minesweeperArray[i][e] = "< >";
                    }

                    completedNoFog = true;
                }
            }
        }
        return completedNoFog;
    } // noFog

    /**
     * This method {@code mark} allows the user to mark a space on the grid
     * assuming that the position they marked is a suspected bomb.
     *
     * @param stdIn uses the user input to anticipate the marking location
     * @return true if mark is completed
     */
    public boolean mark(Scanner stdIn) {
        boolean completedMark = false;
        int markedRow = 0;
        int markedCol = 0;
        for (int x = 0; x < 1; x++) {
            if (stdIn.hasNextInt()) {
                markedRow = stdIn.nextInt();
                if (markedRow < 0 || markedRow > rows ) {
                    System.err.print("Invalid Command: Array index " + markedRow
                                     + " out of bounds for length " + rows);
                    break;
                }
                if (stdIn.hasNextInt()) {
                    markedCol = stdIn.nextInt();
                    if ( markedCol < 0 || markedCol > columns) {
                        System.err.print("Invalid Command: Array index " + markedCol +
                                         " out of bounds for length " + columns);
                        break;
                    }
                    for (int i = 0; i < minesweeperArray.length; i++) {
                        for (int j = 0; j < minesweeperArray[i].length; j++) {
                            if (minesweeperArray[i][j] == "< >") {
                                minesweeperArray[i][j] = null;
                            } else if (minesweeperArray[i][j] == "<F>") {
                                minesweeperArray[markedRow][markedCol] = " F";
                            }
                        }
                    }
                    if (minesweeperArray[markedRow][markedCol] == "  "
                        || minesweeperArray[markedRow][markedCol] == " ?") {
                        minesweeperArray[markedRow][markedCol] = " F";
                        completedMark = true;
                        roundsCompleted++;

                    }
                }
            }
        }
        return completedMark;
    } // mark

    /**
     * This method {@code reveal} allows the user to reveal a space on the grid
     * assuming there isn't a bomb present on the selected space.
     *
     * @param stdIn uses the the input from the main method to
     * reveal the location
     * @return true if reveal is completed
     */
    private boolean reveal(Scanner stdIn) {
        boolean accomplishedReveal = false;
        int revealedRow = 0;
        int revealedColumn = 0;
        if (stdIn.hasNextInt()) {
            revealedRow = stdIn.nextInt();
            if (stdIn.hasNextInt()) {
                revealedColumn = stdIn.nextInt();
                if (!stdIn.hasNextInt() && revealedRow >= 0 && revealedRow < rows
                    && revealedColumn >= 0 && revealedColumn < columns) {
                    if (!isMineArray[revealedRow][revealedColumn]) {
                        // for (int x = 0; x < minesweeperArray.length; x++) {
                        // for (int y = 0; y < minesweeperArray[x].length; y++) {
                        if (minesweeperArray[revealedRow][revealedColumn] == " ?"
                            || minesweeperArray[revealedRow][revealedColumn] == "  ") {
                            String mines = " " + getNumAdjMines(revealedRow, revealedColumn);
                            minesweeperArray[revealedRow][revealedColumn] = mines;
                            System.out.println();
                            accomplishedReveal = true;
                            roundsCompleted++;
                        }
                    }
                    if (isMineArray[revealedRow][revealedColumn]) {
                        printLoss();
                        System.exit(0);

                    }

                }
                if (revealedRow < 0 || revealedRow > rows) {
                    System.err.println("Invalid Command: Array index " + revealedRow
                                       + " out of bounds for length " + columns);
                    if (revealedColumn < 0 || revealedColumn > columns) {
                        System.err.println("Invalid Command: Array index " + revealedColumn
                                           + " out for bounds for length " + rows);
                    }
                }
            }
        }
        return accomplishedReveal;
    } // reveal

    /**
     * This method {@code guess} allows the player to make a guess
     * about a particular space on the grid.
     *
     * @param stdIn takes standard input to use as a command
     * to call the method
     * @return true if guess was completed
     */
    public boolean guess(Scanner stdIn) {
        boolean accomplishedGuess = false;
        int rowGuess = 0;
        int columnGuess = 0;
        if (stdIn.hasNextInt()) {
            rowGuess = stdIn.nextInt();
            if (stdIn.hasNextInt()) {
                columnGuess = stdIn.nextInt();
                for (int i = 0; i < minesweeperArray.length; i++) {
                    for (int j = 0; j < minesweeperArray[i].length; j++) {
                        if (minesweeperArray[i][j] == "< >") {
                            minesweeperArray[i][j] = null;
                        } else if (minesweeperArray[i][j] == "<?>") {
                            minesweeperArray[i][j] = " ?";
                        } else {
                            int o = 0;
                            o++;
                        }
                    }
                }
                if (minesweeperArray[rowGuess][columnGuess] != "< >"
                    || minesweeperArray[rowGuess][columnGuess] == " F") {
                    minesweeperArray[rowGuess][columnGuess] = " ?";
                } else {
                    minesweeperArray[rowGuess][columnGuess] = "<?>";
                }
                accomplishedGuess = true;
                roundsCompleted++;
                System.out.println();
            }
        }

        return accomplishedGuess;
    } // guess

    /**
     * This method determing whether or not a demand is within
     * the range of the array's dimensions.
     *
     * @return true if row and column selection are in bounds of the grid
     * @param row is used to dictate the row selection
     * @param col is used to dictate the column selection
     */
    public boolean isInBounds(int row, int col) {
        if (row < isMineArray.length && row >= 0 && col >= 0 && col < isMineArray[0].length) {
            return true;
        } else {
            return false;
        }
    } // isInBounds

    /**
     * This method prints when a commond is not recognized.
     */
    public void commandNotRecognized() {
        System.out.println();
        System.out.println("This command is not valid.");
        System.out.println();
    } // commandNotRecognized


    /**
     * This method force quits from a standard input.
     */
    public void quit() {
        System.out.println();
        System.out.println("Quitting the game...");
        System.out.println("Bye!");
        System.exit(0);
    } // quit

    /**
     * This method changes to the next turn when called upon.
     */
    public void nextTurn() {

        printRoundsCompleted();
        printMineField();
        promptUser();



    } // quit

    /**
     * This method prints the losing screen to standard output.
     */
    public void printLoss() {
        System.out.println();
        System.out.println("Oh no... You revealed a mine!");
        System.out.println("");
        System.out.println("  __ _  __ _ _ __ ___   ___    _____   _____ _ __");
        System.out.println(" / _` |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__|");
        System.out.println("| (_| | (_| | | | | | |  __/ | (_) \\ V /  __/ |");
        System.out.println(" \\__, |\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|");
        System.out.println(" |___/");
        System.out.println();
        System.exit(0);
    } // printLoss

    /**
     * This method prints the winning screen to standard output.
     */
    public void printWin() {
        System.out.println();
        System.out.println(" ░░░░░░░░░▄░░░░░░░░░░░░░░▄░░░░ " + "\"So Doge\"");
        System.out.println(" ░░░░░░░░▌▒█░░░░░░░░░░░▄▀▒▌░░░ " );
        System.out.println(" ░░░░░░░░▌▒▒█░░░░░░░░▄▀▒▒▒▐░░░ " + "\"Such Score\"");
        System.out.println(" ░░░░░░░▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐░░░");
        System.out.println(" ░░░░░▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐░░░ " + "\"Much Minesweeping\"");
        System.out.println(" ░░░▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌░░░");
        System.out.println(" ░░▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒▌░░ " + "\"Wow\"");
        System.out.println(" ░░▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐░░");
        System.out.println(" ░▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌░");
        System.out.println(" ░▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌░");
        System.out.println(" ▀▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒▐░");
        System.out.println(" ▐▒▒▐▀▐▀▒░▄▄▒▄▒▒▒▒▒▒░▒░▒░▒▒▒▒▌");
        System.out.println(" ▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▐░");
        System.out.println(" ░▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒░▒░▒░▒░▒▒▒▌░");
        System.out.println(" ░▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▄▒▒▐░░");
        System.out.println(" ░░▀▄▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▄▒▒▒▒▌░░");
        System.out.println(" ░░░░▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀░░░ CONGRATULATIONS!");
        System.out.println(" ░░░░░░▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀░░░░░ YOU HAVE WON!");
        System.out.println(" ░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▀▀░░░░░░░░" + " SCORE: " + score());
        System.out.println();
    } // printWin

    /**
     * This method gives the score of the current game.
     *
     * @return the amount of the score
     */
    public double score() {
        double score = 100 * (rows * columns) / this.roundsCompleted;
        return score;
    } // score


    /**
     * This method prints the available commands to the
     * user when called upon.
     */
    private void help() {
        this.roundsCompleted++;
        System.out.println();
        System.out.println("Commands Available...");
        System.out.println(" - Reveal: r/reveal row col");
        System.out.println(" - Mark: m/mark row col");
        System.out.println(" - Guess: g/guess row col");
        System.out.println(" - Help: h/help");
        System.out.println(" - Quit: q/quit");
        System.out.println();
    } // help

    /**
     * This method prints the line where standard input
     * from a user is expected.
     */
    public void printInputLine() {
        System.out.println();
        System.out.print("minesweeper-alpha: ");
    } // printInputLine

    /**
     * This method begins the game.
     */
    public void play() {
        printWelcome();
        while (true) {
            nextTurn();
            if (isWon() == true) {
                break;
            }
        }
        printWin();
    } // play
}  // MinesweeperGame
