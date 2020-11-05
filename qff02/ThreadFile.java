

import java.io.*;





public class ThreadFile implements Runnable {

            private static FileReader reader;
            private static BufferedReader br;
            private static FileWriter writer;
            private static BufferedWriter bw;
    public ThreadFile(FileReader reader1,BufferedReader br1,FileWriter writer1,BufferedWriter bw1) {

        reader=reader1;
        br=br1;
        writer=writer1;
        bw=bw1;
    }

    public static FileReader getReader() {
        return reader;
    }

    public static BufferedReader getBr() {
        return br;
    }

    public static FileWriter getWriter() {
        return writer;
    }

    public static BufferedWriter getBw() {
        return bw;
    }

    @Override
    public  void run() {
        String str=null;

        while (true) {
            try {
                synchronized (this) {
                    if (br==null||!((str = br.readLine()) != null)) break;

                    bw.write(Thread.currentThread().getName()+str+"\n");

                    Thread.sleep(100);
                }
                Thread.yield();
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
            }
        }



    }



    public static void main(String[] args) throws IOException, InterruptedException {


        FileReader reader=new FileReader("D:\\workspace\\task2\\src\\1.txt");
        BufferedReader br=new BufferedReader(reader);
        FileWriter writer=new FileWriter("D:\\workspace\\task2\\src\\2.txt");
        BufferedWriter bw=new BufferedWriter(writer);
        ThreadFile thread=new ThreadFile(reader,br,writer,bw);
        new Thread(thread,"线程1++++").start();
        new Thread(thread,"线程2++++").start();
        Thread.sleep(5000);
        ThreadFile.getBr().close();
        ThreadFile.getBw().close();
        ThreadFile.getReader().close();
        ThreadFile.getWriter().close();

    }
}
