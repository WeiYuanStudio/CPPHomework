package framework;

public class UnderLinePen extends Product {
    private char ulchar;

    public UnderLinePen(char ulchar) {
        this.ulchar = ulchar;
    }

    @Override
    public void use(String info) {
        System.out.println(info);
        for(int i = 0; i < info.length(); i++) {
            System.out.print(ulchar);
        }
        System.out.println();
    }
}