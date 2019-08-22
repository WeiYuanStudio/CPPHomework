public class Main {
    public static void main(String[] args) {
        TicketMaker ticketMaker = TicketMaker.getTicketMaker();

        for(int i = 0; i < 10 ; i++) {
            System.out.println(ticketMaker.getNextTicketNumber());
        }
    }
}