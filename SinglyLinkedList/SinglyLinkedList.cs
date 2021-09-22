using System;

namespace MyNamespace {

  public class Node {
    public dynamic data;
    public Node next;

    public Node(dynamic data){
      this.data = data;
      this.next = null;
    }
  }

  public class SinglyLinkedList {
    private Node root;
    private string error;

    public SinglyLinkedList(dynamic data){
      this.root = new Node(data);
    }

    public Node GetLastNode(){
      Node temp = this.root;

      while(temp.next != null){
        temp = temp.next;
      }

      return temp;
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

    public Node GetNodeBeforeLastNode(){
      if(this.root == null || this.root.next == null){
        return null;
      }

      Node temp = this.root;

      while(temp.next.next != null){
        temp = temp.next;
      }

      return temp;
    }

    public Node GetRootNode(){
      return this.root;
    }

    public string GetError(){
      return this.error;
    }

    public Node InsertFront(dynamic data){
      Node newNode = new Node(data);
      newNode.next = this.root;

      this.root = newNode;

      return newNode;
    }

    public Node InsertLast(dynamic data){
      Node lastNode = this.GetLastNode();
      Node newNode = new Node(data);

      if(lastNode == null){
        this.InsertFront(newNode);
      }else{
        lastNode.next = newNode;
      }

      return newNode;
    }

    public Node InsertAfter(dynamic node, dynamic data){
      Node currentNode = this.GetNode(node);

      if(currentNode == null){
        this.error = "Node " + node.ToString() + " is not found";
        Console.WriteLine(this.error);
        return null;
      }

      Node newNode = new Node(data);
      newNode.next = currentNode.next;
      currentNode.next = newNode;

      return newNode;
    }

    public Node DeleteFront(){
      if(this.root == null){
        return null;
      }

      Node deletedNode = this.root;
      this.root = this.root.next;

      return deletedNode;
    }

    public Node DeleteLast(){
      Node nodeBeforeLastNode = this.GetNodeBeforeLastNode();

      if(nodeBeforeLastNode == null){
        this.error = "Cannot perform task since the list is empty or has only one node";
        Console.WriteLine(this.error);
        return null;
      }

      Node deletedNode = nodeBeforeLastNode.next;
      nodeBeforeLastNode.next = null;

      return deletedNode;
    }

    public Node DeleteAfter(dynamic node){
      Node currentNode = this.GetNode(node);

      if(currentNode == null){
        this.error = "Node " + node.ToString() + " is not found";
        Console.WriteLine(this.error);
        return null;
      }

      if(currentNode.next == null){
        this.error = "Cannot perform task since node " + currentNode.data.ToString() + " is the last node";
        Console.WriteLine(this.error);
        return null;
      }

      Node deletedNode = currentNode.next;

      currentNode.next = currentNode.next.next;

      return deletedNode;
    }

    public void Traverse(){
      Node temp = this.root;

      if(temp != null){
        while(temp != null){
          Console.Write("{0} ", temp.data);
          temp = temp.next;
        }

        Console.WriteLine("");
      }else{
        Console.WriteLine("List is empty");
      }
    }
  }
}
