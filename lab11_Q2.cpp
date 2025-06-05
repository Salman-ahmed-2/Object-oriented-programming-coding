#include <iostream>
#include <string>
using namespace std;

const int MAX_PAGES=10;
const int MAX_PARAGRAPHS=10;
const int MAX_SENTENCES=10;

class Sentence {
private:
    string text;
public:
    Sentence() {}
    Sentence(const string& t) : text(t) {}

    void display(int indent=0) const {
        cout << string(indent,' ')<<"Sentence: \""<<text<<"\""<<endl;
    }
};

class Paragraph {
private:
    Sentence sentences[MAX_SENTENCES];
    int sentenceCount=0;
public:
    void addSentence(const string& sentenceText) {
        if (sentenceCount<MAX_SENTENCES) {
            sentences[sentenceCount++]=Sentence(sentenceText);
        } else {
            cout<<"Maximum number of sentences reached!"<<endl;
        }
    }

    void display(int indent=0) const {
        for (int i=0; i<sentenceCount; ++i) {
            sentences[i].display(indent+4);
        }
    }
};

class Page {
private:
    Paragraph paragraphs[MAX_PARAGRAPHS];
    int paragraphCount=0;
public:
    Paragraph* addParagraph() {
        if (paragraphCount<MAX_PARAGRAPHS) {
            return &paragraphs[paragraphCount++];
        } else {
            cout<<"Maximum number of paragraphs reached!"<<endl;
            return nullptr;
        }
    }

    void display(int pageNumber, int indent=0) const {
        cout<<string(indent, ' ') <<"Page "<<pageNumber<<":"<<endl;
        for (int i=0; i<paragraphCount; ++i) {
            cout<<string(indent+2,' ')<<"Paragraph "<<i+1<<":"<<endl;
            paragraphs[i].display(indent + 4);
        }
    }
};

class Document {
private:
    Page pages[MAX_PAGES];
    int pageCount=0;
public:
    Page* addPage() {
        if (pageCount<MAX_PAGES) {
            return &pages[pageCount++];
        } else {
            cout<<"Maximum number of pages reached!" << endl;
            return nullptr;
        }
    }

    void display() const {
        cout << "Document:"<<endl;
        for (int i=0; i<pageCount; ++i) {
            pages[i].display(i + 1, 2);
        }
    }
};


int main() {
    Document doc;
    Page* page1=doc.addPage();
    Paragraph* para1=page1->addParagraph();
    para1->addSentence("Object-oriented programming is my favourite");
    para1->addSentence("I love oop");
    Paragraph* para2 = page1->addParagraph();
    para2->addSentence("each one has his goal");
    doc.display();
    return 0;
}
