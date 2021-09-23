using System;
using MyNamespace;

namespace MyNamespace {
  public class MyDatabase{
    private CircularDoublyLinkedList record;

    public MyDatabase(dynamic data){
      this.record = new CircularDoublyLinkedList(data);
    }

    private Node GetDataAlgorithm(int id){
      Node records = this.SelectAll();
      Node last = records;

      do{
        if(records.data.id == id){
          return records;
        }
        records = records.prev;
      }while(records != last);

      return null;
    }

    private bool isFirstRecord(int id){
      return id == this.SelectAll().next.data.id;
    }

    private bool isLastRecord(int id){
      return id == this.SelectAll().data.id;
    }

    public Node SelectAll(){
      return this.record.GetRootNode();
    }

    public Node SelectOneData(dynamic data){
      return this.record.GetNode(data);
    }

    public Node InsertData(dynamic data){
      return this.record.InsertFront(data);
    }

    public Node DeleteDataById(int id){
      if(this.isFirstRecord(id)){
        return this.record.DeleteFront();
      }

      if(this.isLastRecord(id)){
        return this.record.DeleteLast();
      }

      Node deletedData = this.GetDataAlgorithm(id);

      if(deletedData == null){
        return null;
      }

      deletedData.prev.next = deletedData.next;
      deletedData.next.prev = deletedData.prev;

      return deletedData;
    }

    public Node CurrentRecord(){
      return this.record.GetCurrentNode();
    }

    public Node NextRecord(){
      return this.record.CurrentNodePrev();
    }

    public Node PrevRecord(){
      return this.record.CurrentNodeNext();
    }
    
    public void UpdateRecord(){
        this.record.CurrentNodeUpdate();
    }
  }
}
