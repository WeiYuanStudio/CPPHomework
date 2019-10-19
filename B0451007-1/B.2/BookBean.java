class BookBean {
    private int id;
    private String title;
    private String isbn;
    private String publisher;
    private String author;
    private int publishYear;

    BookBean(){
        this.id = -1;
    }

    /**
     * Book
     */
    BookBean(int id, String title, String isbn, String publisher, String author, int publishYear) {
        this.id = id;
        this.title = title;
        this.isbn = isbn;
        this.publisher = publisher;
        this.author = author;
        this.publishYear = publishYear;
    }
    
    public int getId() {
        return this.id;
    }
    
    public void setId(int id) {
        this.id = id;
    }
    
    public String getTitle() {
        return this.title;
    }
    
    public void setTitle(String title) {
        this.title = title;
    }

    public String getIsbn() {
        return this.isbn;
    }
    
    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }
    
    public String getPublisher() {
        return this.publisher;
    }
    
    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }
    
    public String getAuthor() {
        return this.author;
    }
    
    public void setAuthor(String author) {
        this.author = author;
    }

    public int getPublishYear() {
        return this.publishYear;
    }
    
    public void setPublishYear(int publishYear) {
        this.publishYear = publishYear;
    }
}
