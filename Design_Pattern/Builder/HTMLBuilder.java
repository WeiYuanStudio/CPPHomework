public class HTMLBuilder extends Builder {
    private StringBuffer strBuffer = new StringBuffer();

    public HTMLBuilder() {
        strBuffer.append("<html><head><title>HTMLBuilder</title></head><body>");
    }

    @Override
    public void makeTitle(String title) {
        strBuffer.append("<h1>" + title + "</h1>");
    }

    @Override
    public void makeString(String str) {
        strBuffer.append("<p>" + str + "</p>");
    }

    @Override
    public void makeItems(String[] items) {
        strBuffer.append("<ul>");
        for (String i : items) {
            strBuffer.append("<li>" + i + "</li>");
        }
        strBuffer.append("</ul>");
    }

    @Override
    public void close() {
        strBuffer.append("</body></html>");
    }

    public String getResult() {
        return strBuffer.toString();
    }
}