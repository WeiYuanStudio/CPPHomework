public class TicketMaker {
    private static TicketMaker ticketMaker = new TicketMaker();
    
    private TicketMaker(){}
    
    private int ticket = 1000;
    
    public int getNextTicketNumber() {
        return ticket++;
    }

    public static TicketMaker getTicketMaker() {
        return ticketMaker;
    }
}