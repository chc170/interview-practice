
public class test {
    static class AA {
        String s;
        int i;
    }

    static void lala( AA aa ) {
        aa.s = "new string";
        aa.i = 1000;
    }

    static void lili( String ss ) {
        ss = "new string";
    }

    public static void main(String[] args) {
        AA aa = new AA();
        aa.s = "old string";
        aa.i = 1;
        
        lala(aa);

        System.out.println(aa.s);
        System.out.println(aa.i);
        
        String ss = new String("old string");
        lili(ss);
        System.out.println(ss);
    }
}

