<h2> Warehouse Management System</h2>
<ul>
<img src="Design of DS.png"> 
  <br>
  <br>
<li>Each of the blue boxes are a part of the linked list. Each node represents a section of the warehouse . The data  part will have two datas, one being of the section number (ex S1,S2..) and the other a head to the stack. The linked list can have as many nodes as many number of sections are there.The next part points to the address of the next node( next section of the warehouse)</li>
<li>Each of the nodes or here, sections of the warehouse have a stack attached to it. Which in real life is equivalent to the goods and shipments the warehouse is storing
  </li>
<li>Every time a shipment is added to the section, it can be pushed to the stack of that particular node (warehouse section) so that when it is time for unloading, the person can keep track of ALL goods and shipments by popping(using pop function) them one by one as they unload it. Hence here we are using the Last in first out property of the stack as the topmost(that went there last)  in shipment or goods in the section will be the first to be unloaded.
  </li>  

