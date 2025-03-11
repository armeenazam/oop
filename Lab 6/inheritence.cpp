#include<iostream>
#include<string>
using namespace std;

class Message{
private:
    string text;
public:
    Message(){text = "";}
    Message(string t){
        text = t;
    }
    virtual string toString(){
        return text;
    }    
    void setText(string t){
        text = t;
    }
    string getText() const { return text; }
};

class SMS :public Message{
private:
    string recipientContactNo;  
public:
    SMS(string t, string r):Message(t){
        recipientContactNo = r;
    }
    void setRecipientContactNo(string r){
        recipientContactNo = r;
    }
    string getRecipientContactNo(){
        return recipientContactNo;
    }
    string toString() override {
        return "SMS to: " + recipientContactNo + "\n" + Message::toString();
    }
};

class Email : public Message{
private:
    string sender;
    string receiver;
    string subject;
public:
    Email(string t, string s, string r, string sub) : Message(t) {
        sender = s;
        receiver = r;
        subject = sub;
    }
    void setSender(string s){
        sender = s;
    }
    void setRecipient(string r){
        receiver = r;
    }
    void setSubject(string sub){
        subject = sub;
    }
    string getSender(){
        return sender;
    }
    string getRecipient(){
        return receiver;
    }
    string getSubject(){
        return subject;
    }
    string toString() override{
        return "Email from: " + sender + "\nEmail to: " + receiver + "\nSubject: " + subject + "\nMessage: " + Message::toString();
    }    
};

bool ContainKeyword(const Message& messageObject, const string& keyword){
    string text = messageObject.getText();
    int textLen = text.length(), keyLen = keyword.length();
    
    for (int i = 0; i <= textLen - keyLen; i++) {
        int j;
        for (j = 0; j < keyLen; j++) {
            if (text[i + j] != keyword[j]) {
                break;
            }
        }
        if (j == keyLen) {
            return true; 
        }
    }
    return false; 
}

string EncodeMessage(const string& message) {
    string encoded = message;
    for (char &c : encoded) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            c = (c == 'Z') ? 'A' : (c == 'z') ? 'a' : c + 1;
        }
    }
    return encoded;
}

int main() {
    SMS sms("Hello, this is a test message.", "1234567890");
    cout << sms.toString() << endl;
    
    Email email("This is a test email.", "alice@example.com", "bob@example.com", "Test Subject");
    cout << email.toString() << endl;
    
    string keyword = "test";
    cout << "\nKeyword Search: '" << keyword << "' in SMS? " << (ContainKeyword(sms, keyword) ? "Yes" : "No") << endl;
    cout << "Keyword Search: '" << keyword << "' in Email? " << (ContainKeyword(email, keyword) ? "Yes" : "No") << endl;
    
    cout << "\nOriginal Message: " << sms.getText() << endl;
    cout << "Encoded Message: " << EncodeMessage(sms.getText()) << endl;
    
    return 0;
}
