package cs1302.p2;

import cs1302.adt.StringList;
import cs1302.adt.FancyStringList;

/**
 * An abstract class used to alter String lists.
 * {@code implements FancyStringList}
 */
public abstract class BaseStringList implements FancyStringList {

    protected int size;

    /**
     * Main empty constructor for the abstract class
     * {@code BaseStringList}.
     */
    public BaseStringList() {
        size = 0;
    } // BaseStringList

    /**
     * This method appends an item to the head of the
     * list.
     *
     * @param item the item to be appened to the list
     * @return true if append is successful, false otherwise
     */
    @Override
    public boolean append(String item) {
        if (item != null && item != "") {
            add(size(), item);
            return true;
        } else if (item == null) {
            throw new NullPointerException("Item is null");
        } else if (item == "") {
            throw new IllegalArgumentException("item is empty");
        } else {

            return false;
        }

    } // append

    /**
     * Is used to tell whether a list is empty.
     *
     * @return true if list is empty, false otherwise
     */
    @Override
    public boolean isEmpty() {
        if (size != 0) {
            return false;
        } else {
            return true;
        } // if
    } // isEmpty

    /**
     * This method makes a string.
     *
     * @param start is the start of a new String
     * @param sep separates the String
     * @param end is the end of the String
     * @return the newly created String
     */
    @Override
    public String makeString(String start, String sep, String end) {
        String separator = "";
        String newString = "";

        if (newString == "" && start != null && sep != null && end != null) {
            for (int i = 0; i < size(); i++) {
                if (i != size()) {
                    separator += get(i);
                    if (i < size() - 1) {
                        separator += sep;
                    }
                }
            }

            newString = start + separator + end;

            return newString;

        } else if (start == null || sep == null || end == null) {
            throw new NullPointerException("Item is null");
        } else {
            return "no new string to make";
        }
    } // makeString

    /**
     * This method adds an item to the tail of a list.
     *
     * @param item is the item to be prepended
     * @return true if prepend is successful, false otherwise
     */
    @Override
    public boolean prepend(String item) {
        if (item != null && item != "") {
            add(0, item);
            return true;
        } else if (item == null) {
            throw new NullPointerException("item is null");
        } else if (item == "") {
            throw new IllegalArgumentException("item is empty");
        } else {
            return false;
        }

    } // prepend

    /**
     * Gives the size of a list.
     * @return the size of a list
     */
    @Override
    public int size() {

        return this.size;
    } // size

    /**
     * This method returns a String of the current list items.
     * @return a String of a list's item(s)
     */
    @Override
    public String toString() {

        return makeString("[" ,", " , "]");
    } // toString

    /**
     *This method adds a list to another list at a certain position.
     *
     * @param index position of items to be added at
     * @param items list of items to be added
     *
     * @return true if add is successful, false otherwise
     */
    @Override
    public boolean add(int index, StringList items) {
        if (index >= 0 && index <= size && items != null) {
            int help = 0;
            for (int i = 0; i < items.size() - 1; i++) {
                add(index + help, items.get(i));
                help++;
            } // for

            return true;
        } else if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Out of bounds index.");
        } else if (items == null) {
            throw new NullPointerException("Null value");
        } else {
            return false;
        }
    } // add

    /**
     * This method adds a list of items to the end of a list.
     *
     * @param items is the list of items
     * @return true if append is complete, false otherwise
     */
    @Override
    public boolean append(StringList items) {
        if (!items.isEmpty()) {
            int help = size();
            for (int x = 0; x < items.size(); x++) {

                add(help, items.get(x));
                help++;
            } // for

            return true;
        } else {
            throw new NullPointerException("Null pointer");
        } // if
    } // append

    /**
     * This method tells the user whether is list
     * contains a specific String item.
     *
     * @param start is the start the list from which to look for the item
     * @param target the item to be looked for
     * @return true if contains is successful, false otherwise
     */
    @Override
    public boolean contains(int start, String target) {
        if (start >= 0 && start <= size && target != null && target != "") {
            for (int i = 0; i < size; i++) {
                String help = get(i);
                if (help.contains(target)) {
                    return true;
                } // if
            } // for
        } else if (target == null) {
            throw new NullPointerException("target is null");
        } else if (target == "") {
            throw new IllegalArgumentException("target has an illegal argument");
        } else if (start < 0 || start > size) {
            throw new IndexOutOfBoundsException("start is invalid");
        } else {
            return false;
        }
        return false;
    } // contains

    /**
     * This method gives the index of a specific String item,
     * if contained in the list.
     *
     * @param start is the start of thelist from which to look for the item
     * @param target the item to be looked for
     * @return index integer number
     */
    @Override
    public int indexOf(int start, String target) {
        int k = start;
        String help = null;

        for (k = start; k < size; k++) {
            help = get(k);

            if (help.contains(target)) {
                return k;
            } // if

        } // for
        return -1;
    } // indexOf

    /**
     * This method adds a list of items to the beginning of a another list.
     *
     * @param items a list of items to be prepended
     * @return true if prepend is successful
     */
    @Override
    public boolean prepend(StringList items) {

        if (items != null) {
            int help = 0;
            for (int i = 0; i < items.size() - 1; i++) {
                add(i, items.get(i));
            } // for
            return !items.isEmpty();
        } else {
            throw new NullPointerException("Null pointer");
        } // if
    } // prepend

} // BaseStringList
