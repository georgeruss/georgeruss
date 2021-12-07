package cs1302.p2;

import cs1302.adt.StringList;
import cs1302.adt.FancyStringList;

/**
 * An array string list class that stores data
 * by using an array.
 *
 * {@code extends BaseStringList}
 */
public class ArrayStringList extends BaseStringList {

    private String[] items = new String[99999];
    private int head;
    private StringList copy;

    /**
     * Main constructor for the ArrayStringList class.
     */
    public ArrayStringList() {

        this.head = size;
    } // ArrayStringList

    /**
     * This methods adds items into a list.
     *
     * @param index the place in which the item will be added to
     * @param item the item to be added
     * @return true if method completes the add of the item
     */
    @Override
    public boolean add(int index, String item) {
        if (index >= 0 && item != null && index >= 0 && index <= size && item != "") {
            if (index > items.length) {

                String[] newItems = new String[items.length * items.length];
                for (int i = 0; i < items.length; i++) {
                    newItems[i] = items[i];
                }

                newItems[index] = item;

                size++;
                return true;
            } else {
                if (items[index] == null) {
                    items[index] = item;

                } else {
                    String help = null;
                    int x = 0;
                    String[] newItems = new String[items.length];

                    for (int i = index; i < items.length; i++) {
                        newItems[index] = item;

                    }

                    for (int j = 0; j < items.length; j++) {
                        if (newItems[j] == null) {
                            newItems[j] = items[x];
                            items[x] = newItems[x];
                            x++;
                        }
                    }
                }
                size++;
                return true;
            }
        } else if (item == null) {
            throw new NullPointerException("Item is null");
        } else if (index > size || index < 0) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        } else if (item == "") {
            throw new IllegalArgumentException("Item is empty");
        } else {
            return false;
        } // if
    } // add

    /**
     * This method clears the current list.
     */
    @Override
    public void clear() {
        for (int i = 0; i < items.length; i++) {
            items[i] = null;
            size = 0;
        } // for
        //sizeCheck("clear");
    } // clear

    /**
     * This method return the item at the selected index.
     *
     * @param index index of the selected item
     * @return a String of the selected item
     */
    @Override
    public String get(int index) {
        if (index >= 0 && index <= size - 1) {
            String get = items[index];
            return get;
        } else if (index < 0 || index > size - 1) {
            throw new IndexOutOfBoundsException("index invalid");
        } else {
            String noGet = "Invalid index selection.";
            return noGet;
        } // if
    } // get

    /**
     * This method removes items from the current list.
     *
     * @param index index of the selected items to be removed
     * @return a String of the item to be removed
     */
    @Override
    public String remove(int index) {
        if (index >= 0 && index <= size - 1) {
            String remove = items[index];
            if (index >= 0) {
                for (int i = index; i < size - 1; i++) {
                    items[i] = items[i + 1];
                }
            }

            size--;
            return remove;
        } else if (index < 0 || index > size - 1) {
            throw new IndexOutOfBoundsException("index out of bounds");
        } else {

            return "Cannot remove a non-existent element";
        } // if

    } // remove

    /**
     * This method slices a list of strings and copies
     * the selected section to hold in another array.
     *
     * @param start is the start of a sliced list
     * @param stop is the end of a sliced list
     *
     * @return a new object of type StringList
     */
    @Override
    public StringList slice(int start, int stop) {
        StringList slice = new ArrayStringList();

        int x = 0;
        if (start < 0 || stop > size || start > stop) {
            throw new IndexOutOfBoundsException("out of bounds");
        } // if
        for (int i = start; i < stop; i++) {
            slice.add(x, items[i]);
            x++;
        } // for
        return slice;
    } // slice

    /**
     * Creates a new list containing the items of
     * another string list.
     *
     * @param other other list of strings
     */
    public ArrayStringList(StringList other) {

        if (other == null) {
            throw new NullPointerException("StringList object is null");
        } // if

        for (int i = 0; i < other.size(); i++) {
            add(i, other.get(i));

        }

    } // ArrayStringList

    /**
     * This method slices a list of strings and copies
     *  the selected section to hold in another array.
     *
     * @param start is the start of a slice list
     * @param stop is the stop of a slice list
     * @param step is the number of values to skip over to copy
     *
     * @return a new object of type FancyStringList
     */
    @Override
    public FancyStringList slice(int start, int stop, int step) {
        FancyStringList slice = new ArrayStringList();
        int x = 0;
        if (start < 0 || stop > size || start > stop) {
            throw new IndexOutOfBoundsException("index out of bounds");
        } // if

        for (int i = start; i < stop;) {

            slice.add(x, items[i]);

            i = i + (1 * step);

            x++;
        }
        return slice;
    } // slice

    /**
     * This method returns a reverse version of the current list.
     * @return a reversed list of type FancyStringList of strings
     */
    @Override
    public FancyStringList reverse() {

        FancyStringList list = new ArrayStringList();
        int x = 0;

        for (int i = size - 1; i > -1;) {

            list.add(x, items[i]);
            i--;
            x++;

        } // for

        return list;

    } // reverse

} // ArrayStringList
