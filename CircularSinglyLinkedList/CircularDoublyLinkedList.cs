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

  public class CircularDoublyLinkedList {
    private Node last;
    private string error;
    private Node currentNode;

    public CircularDoublyLinkedList(dynamic data){
      this.last = new Node(data);

      this.last.next = this.last;
      this.last.prev = this.last;

      this.currentNode = this.last;
    }

    public void CurrentNodeUpdate(){
      this.currentNode = this.last;
    }

    public Node GetCurrentNode(){
      return this.currentNode;
    }

    public Node CurrentNodeNext(){
      this.currentNode = this.currentNode.next;
      return this.currentNode;
    }

    public Node CurrentNodePrev(){
      this.currentNode = this.currentNode.prev;
      return this.currentNode;
    }

    public Node GetRootNode(){
      return this.last;
    }

    public Node GetNode(dynamic data){
      if(this.last == null){
        return null;
      }

      Node temp = this.last.next;

      do{
        if(temp.data == data){
          break;
        }

        temp = temp.next;
      }while(temp != this.last.next);

      return temp;
    }

    public Node InsertFront(dynamic data){
      Node newNode = new Node(data);

      if(this.last == null){
        this.last = newNode;

        this.last.next = this.last;
        this.last.prev = this.last;

      }else{
        newNode.next = this.last.next;
        newNode.prev = this.last;

        this.last.next.prev = newNode;
        this.last.next = newNode;
      }

      return newNode;
    }

    public Node InsertLast(dynamic data){
      if(this.last == null){
        return this.InsertFront(data);
      }

      Node newNode = new Node(data);
      newNode.next = this.last.next;
      newNode.prev = this.last;

      this.last.next.prev = newNode;
      this.last.next = newNode;

      this.last = newNode;

      return newNode;
    }

    public Node InsertAfter(dynamic node, dynamic data){
      if(this.last == null){
        this.error = "List is empty";
        Console.WriteLine(this.error);
        return null;
      }

      Node currentNode = this.GetNode(node);

      if(currentNode == null){
        this.error = "Node " + node.ToString() + " is not found";
        Console.WriteLine(this.error);
        return null;
      }

      if(currentNode == this.last){
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

      if(this.last == null){

        this.error = "List is empty";
        Console.WriteLine(this.error);
        return null;

      }

      if(this.last == this.last.next){
        this.last = null;
        return this.last;
      }

      Node deletedNode = this.last.next;

      this.last.next.next.prev = this.last;
      this.last.next = this.last.next.next;

      return deletedNode;
    }

    public Node DeleteLast(){

      if(this.last == null){

        this.error = "List is empty";
        Console.WriteLine(this.error);
        return null;

      }

      if(this.last == this.last.next){
        this.last = null;
        return this.last;
      }

      Node deletedNode = this.last;

      this.last.prev.next = this.last.next;
      this.last.next.prev = this.last.prev;
      this.last = this.last.prev;

      return deletedNode;
    }

    public Node DeleteAfter(dynamic node){
      if(this.last == null){
        this.error = "List is empty";
        Console.WriteLine(this.error);
        return null;
      }

      Node currentNode = this.GetNode(node);

      if(currentNode == null){
        this.error = "Node " + node.ToString() + " is not found";
        Console.WriteLine(this.error);
        return null;
      }

      if(currentNode == this.last){
        return this.DeleteLast();
      }

      Node deletedNode = currentNode.next;

      currentNode.next = currentNode.next.next;
      currentNode.next.next.prev = currentNode;

      return deletedNode;
    }

    public void Traverse(){
      if(this.last == null){
        this.error = "List is empty";
        Console.WriteLine(this.error);
        return;
      }

      Node temp  = this.last.next;

      do {
        Console.Write("{0} ", temp.data);
        temp = temp.next;
      }while(temp != this.last.next);

      Console.WriteLine("");
    }

    public void TraversePrev(){

      if(this.last == null){
        this.error = "List is empty";
        Console.WriteLine(this.error);
        return;
      }

      Node temp = this.last;

      do{
        Console.Write("{0} ", temp.data);
        temp = temp.prev;
      }while(temp != this.last);

      Console.WriteLine("");
    }
  }
}
