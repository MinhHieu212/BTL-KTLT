/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0){
		this->x = x;
		this->y = y;
	}
	    string toString() const{
		return "<Point[" + to_string(this->x) + "," + to_string(this->y) + "]>";
    }

    int distanceTo(const Point & otherPoint) const{
		double d;
		d = sqrt(pow(this->x - otherPoint.x, 2) + pow(this->y - otherPoint.y, 2));
		return ceil(d);
    }
};


class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
	Node(){
		Point poi(0,0);
		this->point = poi;
		this->next = nullptr;
	}
    Node(const Point & point=Point(), Node * next=NULL){
		this->point = point;
		this->next = next;
    }
	string toString() const{
	    return "<Node["+ this->point.toString()+ "]>";
    }
    void setNext(Node* node){
    	this->next= node;
	}
	Node* getNext(){ 
		return this->next;
	}
	Point getPoint(){
		return this->point;
	}
};

 
class Path {
private:
    Node *head;
    Node *tail;
    int count;
    int length;
    
public:
    Path(){
    	this->head = nullptr;
    	this->tail = nullptr;
    	this->count = 0;
    	this->length = -1;
	}
    ~Path(){
    	this->head = nullptr;
    	this->tail = nullptr;
    	this->count = 0;
    	this->length = -1;
	}

    void addPoint(int x, int y){
    	this->count++;
    	Point point(x,y);
    	Node *node = new Node(point , nullptr); 
    	Node *tmp = this->head;
        if(this->count == 1){
        	this->head = node;
        	this->tail = node;
		}else{
             for(int i = 0 ; i < (this->count-2) ; i++){
             	tmp = tmp->getNext();
			 }
			 tmp->setNext(node);
			 this->tail = node;
		}
	    if(this->count == 1){
	    	this->length = 0;
		}else{
			this->length = this->length + tmp->getPoint().distanceTo(tmp->getNext()->getPoint());
		}
	}
	
    string toString() const{
	    string StrNode = "";
	    for(Node *tmp = head ;  tmp != nullptr ; tmp = tmp->getNext()){
	    	StrNode += tmp->toString();
	    	if(tmp->getNext() != nullptr){
	    		StrNode += ",";
			}
		}
			return "<Path[count:" + to_string(this->count) + ",length:" + to_string(this->length) + ",[" + StrNode + "]]>";
	}
				
				
	Point getLastPoint() const{
		return tail->getPoint();
	}
	
	int GetDis(Point p) const{
		return tail->getPoint().distanceTo(p);
	}
	
	int len() const{
		return this->length;
	}
};

class Character {
private:
    string name;
    Path *path;

public:
    Character(const string & name=""){
    	this->name = name;
    	this->path = new Path();
	}
    ~Character(){
    	delete this->path;
	}

    string getName() const{
		return this->name;
	}
    void setName(const string & name){
    	this->name = name;
	}

    void moveToPoint(int x, int y){
    	this->path->addPoint(x,y);
	}
	
    string toString() const{
	return "<Character[name:"+ this->name + ",path:" + this->path->toString() +"]>";
	}
	int len1() const{
	return this->path->len();
	}
	Point getP() const{
		return this->path->getLastPoint();
	}
	int getDis1(Point p1) const{
		return this->path->GetDis(p1);
	}
};

bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {
        int l1 , l2;
	    l1 = chWatson.len1();
	    l2 = chMurderer.len1();
	    Point d1 = chWatson.getP();
	    int dis = chMurderer.getDis1(d1);
	    if(l1-l2 <= maxLength){
	    	outDistance = dis;
	    	if(outDistance <= maxDistance){
	    		return true;
			}else {
				return false;
			}
		}else{
			outDistance = -1;
			return false;
		}
	    return true;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
