public class TextBuilder extends Builder {
    private StringBuffer strBuffer = new StringBuffer();

    @Override
    public void makeTitle(String title) {
        strBuffer.append("================\n");
        strBuffer.append("<" + title + ">\n");
    }

    @Override
    public void makeString(String str) {
        strBuffer.append(">  " + str + "\n");
    }

    @Override
    public void makeItems(String[] items) {
        for (String i : items) {
            strBuffer.append("\t> " + i + "\n");
        }
    }
    
    @Override
    public void close() {
        strBuffer.append("================\n");
    }
    
    @Override
    public String getResult() {
        return strBuffer.toString();
    }
}