
struct node
{
  int data;
  node *next;
};


class List
{
  private:
    node *head, *tail;

  public:
    List();

    void append(int data);
    void insert_start(int data);
    void insert_end(int data); // this is just append
    void insert(int pos, int data);

    void remove_start();
    void remove_end();
    void remove(int pos);

    void display();

};




