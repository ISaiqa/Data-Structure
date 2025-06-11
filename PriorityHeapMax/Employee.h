class Employee {
public:
    float priority;  // Changed from int to float
private:
    int E_id;
    string name;
    string dept;
    float exp;
public:
	Employee() : E_id(0), name(""), dept(""), exp(0.0f), priority(0.0f) {}
    Employee(int id, string n, string d, float e)
	{
        E_id = id;
        name = n;
        dept = d;
        exp = e;
        priority = exp; // exp is already float, so no cast needed
    }

    // Getters
    int getE_id() { return E_id; }
    string getName() { return name; }
    string getDept() { return dept; }
    float getExp() { return exp; }
    

    // Setters
    void setE_id(int id) { E_id = id; }
    void setName(string n) { name = n; }
    void setDept(string d) { dept = d; }
    void setExp(float e) { exp = e; priority = e; }

    void display() {
        cout << "ID: " << E_id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Experience: " << exp << " years" << endl;
    }
};