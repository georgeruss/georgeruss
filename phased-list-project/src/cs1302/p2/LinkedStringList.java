package cs1302.p2;

import cs1302.adt.StringList;
import cs1302.adt.Node;
import cs1302.adt.FancyStringList;

/**
 * A child class of BaseStringList,
 * it defines undefined expressed in StringList.
 *
 * {@code extends BaseStringList}
 */
public class LinkedStringList extends BaseStringList {

    private Node head;
    private Node tail;
    private Node current;
    private String makeList;

    /**
     * Main Constructor for the LinkedStringList class.
     */
    public LinkedStringList() {
        this.size = 0;
        this.head = null;
        this.tail = null;
        this.current = null;
        this.makeList = null;
    } // LinkStringList

    /**
     * This method adds items into a list.
     *
     * @param index the place in which the item will be added
     * @param item the item to be added
     * @return true if method completes the add of the item
     * @throws NullPointerException if item is null
     * @throws IllegalArgumentException if item is empty
     * @throws IndexOutOfBoundsException if the index is out bounds
     */
    @Override
    public boolean add(int index, String item) {

        Node newNode = new Node(item, null);
        Node temp = head;

        if (index >= 0 && item != null && index <= size && item != "") {
            if (index > 0 && index <= size - 1 && size > 0)  {

                if (get(index) != null) {
                    for (int i = index; i < size - 1; i++) {
                        temp = temp.getNext();

                    }
                    newNode.setNext(temp.getNext());
                    temp.setNext(newNode);


                } else {
                    head = new Node(item, head);
                } // if

                current = head;
                size++;
                return true;
            } else {

                if (size == 0 && size == 0) {

                    head = new Node (item, null);
                    tail = head;
                } else {
                    head = new Node (item, head);

                } // if

                current = head;
                size++;
                return true;
            }

        } else if (item == null) {
            throw new NullPointerException("item is null");
        } else if (item == "") {
            throw new IllegalArgumentException("item is empty");
        } else if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("out of bounds");
        } else {
            return false;
        } // if
    }  // add

    /**
     * This method clears the current list.
     */
    @Override
    public void clear() {

        head = null;

        size = 0;
    } // clear

    /**
     * This method returns the item at the selected index.
     *
     * @param index index of the selected item
     * @return a String of the selected item
     */
    @Override
    public String get(int index) {
        String element = "";
        Node help = null;
        current = head;
        if (head != null && index >= 0 && index < size && size > 0) {
            if (index > 0 && index < size - 1) {

                for (int i = size - 1; i > index; i--) {
                    current = current.getNext();

                }

                element = current.getItem();
                return element;

            } else if (index == size - 1) {
                element = head.getItem();
                return element;
            } else if (index == 0) {

                element = tail.getItem();

                return element;

            } else {
                return "not valid";
            }

        } else if (index < 0 || index >= size ) {
            throw new IndexOutOfBoundsException("index is out of bounds");
        } else {
            return "current node is null";
        }
    } // get

    /**
     * This method removes items from the current list.
     *
     * @param index index of the selected item to be removed
     * @return a String of the item to be removed
     */
    @Override
    public String remove(int index) {
        String element = null;
        Node help = head;
        Node next = head;
        if (head != null && size > 0 && index < size && index >= 0) {
            if (index < size - 1 && index > 0) {
                for (int i = index; i < size - 1; i++) {
                    help = help.getNext();
                }

                help.setNext(help);
                element = get(index);
                size--;
                return element;
            } else if (index == 0 || index == size - 1) {
                element = get(index);
                if (index == 0) {
                    int counter = size - 1;
                    while (counter != 0) {
                        help = help.getNext();
                    }
                } else {
                    head =  head.getNext();
                }

                size--;

                return element;

            } else {
                current = head;
                element = head.getItem();
                size--;
                return element;
            }

        } else if (index <= 0 || index >= size) {
            throw new IndexOutOfBoundsException("index out of bounds");
        } else {
            element = "not valid to remove";
            return element;
        }

    } // remove


    /**
     * This method slices a list of strings a copies
     * the selected section to hold in another Node.
     *
     * @param start is the start of a sliced list
     * @param stop is the end of a sliced list
     *
     * @return a new objects of type StringList
     */
    @Override
    public StringList slice(int start, int stop) {
        StringList slice = new LinkedStringList();
        if (start < 0 || stop < size || start > stop || start > size || stop > size) {
            throw new IndexOutOfBoundsException("out of bounds");
        } else {
            int h = 0;
            for (int i = start; i < stop; i++) {
                slice.add(h, get(i));
                h++;
            }
            return slice;
        }
    } // slice

    /**
     * LinkedStringList parameter that copies a string list.
     * @param other a different string list used to copy
     */
    public LinkedStringList(StringList other) {

        for (int i = 0; i < other.size(); i++) {
            add(i, other.get(i));
        }
    } // LinkedStringList

    /**
     * This method slices a list of strings a copies
     * the selected section to hold in another Node.
     *
     * @param start is the start of a sliced list
     * @param stop is the end of a sliced list
     *
     * @return a new objects of type StringList
     */
    @Override
    public FancyStringList slice(int start, int stop, int step) {
        FancyStringList slice = new LinkedStringList();
        int x = 0;
        if (start < 0 || stop > size || start > stop || start > size || stop > size) {
            throw new IndexOutOfBoundsException("out of bounds");
        }

        for (int i = start; i < stop;) {
            slice.add(x, get(i));

            i = i + (1 * step);

            x++;
        }
        return slice;
    } // slice

    /**
     * This method reverses the current string list's items.
     *
     * @return a reverse version of the current list
     */
    @Override
    public FancyStringList reverse() {
        FancyStringList list = new LinkedStringList();
        int x = size - 1;

        for (int i = 0; i <= size - 1; i++) {
            list.add(i, get(x));
            x--;
        }

        return list;
    } // reverse
} // LinkedStringList
