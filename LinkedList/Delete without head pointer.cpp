//https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1#
void deleteNode(Node *node)
{
   // Your code here
   Node *temp=node;
   while(node->next!=nullptr)
   {
       node->data=node->next->data;
       temp=node;
       node=node->next;
   }
   free(node);
   temp->next=nullptr;
}

