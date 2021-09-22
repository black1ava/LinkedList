using System;

namespace MyNamespace {

  public class Node {
    public dynamic data;
    public Node next;
    public Node prev;

    public Node(dynamic data){
      this.data = data;
      this.next = this.prev = null;
    }
  }

  public class DoublyLinkedList {
    private Node root;
    private string error;

    public DoublyLinkedList(dynamic data){
      this.root = new Node(data);
    }

    public Node GetNode(dynamic data){
      Node temp = this.root;

      while(temp != null){
        if(temp.data == data){
          break;
        }

        temp = temp.next;
      }

      return temp;
    }

    public Node GetLastNode(){
      Node temp = this.root;

      while(temp.next != null){
        temp = temp.next;
      }

      return temp;
    }

    public Node InsertFront(dynamic data){

      Node newNode = new Node(data);

      if(this.root == null){
        return newNode;
      }

      newNode.next = this.root;
      this.root.prev = newNode;
      this.root = newNode;

      return newNode;
    }

    public Node InsertLast(dynamic data){
      if(this.root == null){
        return this.InsertFront(data);
      }

      Node newNode = new Node(data);
      Node lastNode = this.GetLastNode();

      newNode.prev = lastNode;
      lastNode.next = newNode;

      return newNode;
    }

    public Node InsertAfter(dynamic node, dynamic data){

      if(this.root == null){
        this.error = "List empty";
        Console.WriteLine(this.error);
        return null;
      }

      Node currentNode = this.GetNode(node);

      if(currentNode == null){
        this.error = this.error = "Node " + node.ToString() + " is not found";
        Console.WriteLine(this.error);
        return null;
      }

      if(currentNode == this.GetLastNode()){
        return this.InsertLast(data);
      }

      Node newNode = new Node(data);

      newNode.next = currentNode.next;
      newNode.prev = currentNode;

      currentNode.next.prev = newNode;
      currentNode.next = newNode;

      return newNode;
    }

    public Node DeleteFront(){
      if(this.root != null){
        Node deletedNode = this.root;

        this.root.next.prev = null;
        this.root = this.root.next;

        return deletedNode;
      }

      this.error = "List empty";
      Console.WriteLine(this.error);
      return null;
    }

    public Node DeleteLast(){
      if(this.root == null){
        this.error = "List is empty";
        Console.WriteLine(this.root);
        return null;
      }

      Node lastNode = this.GetLastNode();

      lastNode.prev.next = null;

      return lastNode;
    }

    public Node DeleteAfter(dynamic data){
      if(this.root == null){
        this.error = "List empty";
        Console.WriteLine(this.error);
        return null;
      }

      Node currentNode = this.GetNode(data);

      if(currentNode == null){
        this.error = this.error = "Node " + data.ToString() + " is not found";
        Console.WriteLine(this.error);
        return null;
      }

      Node deletedNode = currentNode.next;

      currentNode.next.next.prev = currentNode;
      currentNode.next = currentNode.next.next;

      return deletedNode;
    }

    public void Traverse(){
      if(this.root == null){
        Console.WriteLine("List is empty");
        return;
      }

      Node temp = this.root;

      while(temp != null){
        Console.Write("{0} ", temp.data);
        temp = temp.next;
      }

      Console.WriteLine("");
    }

    public void TraversePrev(dynamic data){
      Node currentNode = this.GetNode(data);

      if(currentNode == null){
        this.error = "Node " + data.ToString() + " is not found";
        Console.WriteLine(this.error);
        return;
      }

      while(currentNode != null){
        Console.Write("{0} ", currentNode.data);
        currentNode = currentNode.prev;
      }

      Console.WriteLine("");
    }

    public void TraverseNext(dynamic data){
      Node currentNode = this.GetNode(data);

      if(currentNode == null){
        this.error = "Node " + data.ToString() + " is not found";
        Console.WriteLine(this.error);
        return;
      }

      while(currentNode != null){
        Console.Write("{0} ", currentNode.data);
        currentNode = currentNode.next;
      }

      Console.WriteLine("");
    }
  }
}
