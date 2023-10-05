import java.util.*;

class Encrypter {
    public:

    String getEncryptedName(String name) {
        
        Validator obj = new Validator();
        Boolean flag = obj.validate(name);
        
        String answer;
        
        if(flag) {
            StringBuffer sbr = new StringBuffer(name);
            sbr.reverse();
            answer = sbr.toString();

            answer.toLowerCase();
        }
        else {
            try {
                throw new IllegalArgumentException();
            }
            catch (IllegalArgumentException e) {
                System.out.println("Try again with valid name");
            }
        }

        return answer;
    }
}