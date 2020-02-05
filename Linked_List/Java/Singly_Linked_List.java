import java.util.Scanner;

public class Singly_Linked_List {

    Node head;

    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    public static Singly_Linked_List InsertLast(Singly_Linked_List list, int data) {
        Node temp = new Node(data);
        temp.next = null;

        if (list.head == null) {
            list.head = temp;
        } else {
            Node p;
            p = list.head;
            while (p.next != null) {
                p = p.next;
            }
            p.next = temp;
        }
        return list;
    }

    public static Singly_Linked_List InsertTop(Singly_Linked_List list, int data) {
        Node temp = new Node(data);
        if (list.head == null) {
            list.head = temp;
            temp.next = null;
        } else {
            temp.next = list.head;
            list.head = temp;
        }
        return list;
    }

    public static void Display(Singly_Linked_List list) {
        Node p = list.head;
        while (p != null) {
            System.out.print("\t" + p.data);
            p = p.next;
        }
    }

    private static Scanner input;

    public static void main(final String args[]) {
        int n, f = 1, x;
        input = new Scanner(System.in);
        Singly_Linked_List list = new Singly_Linked_List();

        do {

            System.out.print("\n\n\n--------------------------------------------------------------------");
            System.out.println("\n| 1 -> For Insert Node at Last of Linked List");
            System.out.println("| 2 -> For Insert Node at Top of Linked List");
            System.out.println("| 3 -> For Display Linked List");
            System.out.println("| 10 -> Exit");
            System.out.print("--------------------------------------------------------------------");
            System.out.print("\n\nEnter Your Choice: ");
            n = input.nextInt();

            switch (n) {
            case 1: {
                System.out.print("\nEnter The data: ");
                x = input.nextInt();
                list = InsertLast(list, x);
                break;
            }
            case 2:{
                System.out.print("\nEnter The data: ");
                x = input.nextInt();
                list = InsertTop(list, x);
                break;
            }
            case 3: {
                System.out.print("\nDisplay:\t");
                Display(list);
                break;
            }
            case 10: {
                f = 0;
                break;
            }

            default: {
                System.out.println("\nInvalid Input");
            }

            }
        } while (f != 0);
    }
}