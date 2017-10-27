/* 
* Make My Ostream.cpp
*
*  created on: 21 May 2016 03:11:07
*      author: alcanderian
*/

include <cstdio>
namespace sanjin {
struct sanjinpres {
    int pres;
};

class myostream {
 public:

    myostream() : fixed(false), hex(false), pres(-1) {

    }

    myostream& operator <<(const int& i) {
        !hex? printf("%d", i): printf("%x", i);
        return *this;
    }
    myostream& operator <<(const double& d) {
        char str[100];
        sprintf(str, "%lf", d);
        if(fixed) pres != -1? printf("%.*lf", pres, d): printf("%lf", d);
        else pres != -1? printf("%.*s", pres + 1, str): printf("%lf", d);
        return *this;
    }

    myostream& operator <<(const char& c) {
        printf("%c", c);
        return *this;
    }

    myostream& operator <<(const char* s) {
        printf("%s", s);
        return *this;
    }


 


    myostream& operator <<(myostream& (*pf)(myostream&)) {


        return pf(*this);


    }


 


    myostream& operator <<(const sanjinpres& pres) {


        this->pres = (pres.pres > 6)? 6: pres.pres;


        return *this;


    }


 


    void setfix() {


        fixed = true;


    }


 


    void sethex() {


        hex = true;


    }


 


 private:


    bool fixed;


    bool hex;


    int pres;


} myout;


 


myostream& myendl(myostream& os) {


    os << '\n';


    return os;


}


 


myostream& myfixed(myostream& os) {


    os.setfix();


    return os;


}


 


myostream& myhex(myostream& os) {


    os.sethex();


    return os;


}


 


sanjinpres mypres(int pres) {


    return {


        pres


    };


}


 


} /* namespace sanjin */


 


using namespace sanjin;


 

