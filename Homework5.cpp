#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// For this homework, you are going to implement an extendable vector based queue that 
// uses "jump" trick to save space. 
// Finish function 
//              front() that prints the first element in the queue
//              deque() that dequeues the queue
//          	enque(val) that enqueues val to the queue
//              print_vect() that prints out vect_que.
// Demonstrate that your code works in main.
// Refer to class PPT if you forgot all the different cases. 

template <class T>
class vect_queue {
	std::vector<T> vect_que;
	size_t size_;
	int que_front_;
    size_t que_back_;
public:
	// template <class T>
	vect_queue(T val) {
		vect_que.push_back(val);
		size_ = 1;
		que_front_ = 0;
        que_back_ = 0;
	}
	T front() const;
    T back() const;
	void deque();
	void enque(T val);
	void print_vect() const;
};

template <class T>
T vect_queue<T>::front() const{
    //cout << "que_front_: " << que_front_ << endl;
    return vect_que.at(que_front_);
}
template <class T>
T vect_queue<T>::back() const{
    //cout << "que_back_: " << que_back_ << endl;
    return vect_que.at(que_back_);
}
template <class T>
void vect_queue<T>::deque(){
    vect_que.erase(vect_que.begin());
    size_--;
    que_back_--;
}

template <class T>
void vect_queue<T>::enque(T val){
    vect_que.push_back(val);
    size_++;
    que_back_ = que_front_ + size_ - 1;
    //cout << "size: " << size_ << ", que_back: " << que_back_ << " ";
}

template <class T>
void vect_queue<T>::print_vect() const{
    int i;
    for(i = 0; i < size_; i++){
        cout << vect_que.at(i) << " ";
    }
    cout << "\n\n";
}

// template <class T>
int main()
{   
    //Demonstrate your code works by adding/removing values in a vect_que class 
    //object. Print out your result.
    //You should include front index of queue, back index of queue, and the entire
    //vector (not queue) for each case.
    //case 1: add to an empty queue

    cout << "Add to an empty queue:\n";
    int val;
    cout << "Enter a value: ";
    cin >> val;

    vect_queue<int> que(val);
    cout << "First Index: " << que.front() << endl << 
            "Back Index: " << que.back() << endl << "Entire Vector: "; 
    que.print_vect(); // end

    //case 2: add to a non-empty queue without jump 
    cout << "Add to a non-empty queue without jump:\n";

    while(val != -1){
        cout << "Enter a value (enter -1 to exit):";
        cin >> val;
        if(val == -1){
            break;
        }
        que.enque(val);
    }
    cout << "First Index: " << que.front() << endl << 
            "Back Index: " << que.back() << endl << "Entire Vector: "; 
    que.print_vect();

    //case 3: add to a non-empty queue with a jump
    
    //case 4: remove from a queue with number of elements > 1 
    //        and que.front not at vect.back
    cout << "Remove from a queue with number of elements > 1: \n";

    que.deque();
    cout << "First Index: " << que.front() << endl << 
            "Back Index: " << que.back() << endl << "Entire Vector: "; 
    que.print_vect(); // end

    //case 5: remove from a queue with number of elements > 1 
    //        and que.front at vect.back
    
    //case 6: remove from a queue with 1 element in it and que.front 
    //        not at vect[0]
    if(que.front() == que.back()){
        cout << "Remove from a queue with 1 elemet in it: \n";
        que.deque();
        cout << "Entire Vector: ";
        que.print_vect();
    } //end

    cout<<"\nprogram ends here.\n";

    return 0;
}