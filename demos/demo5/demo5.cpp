#include <QtCore>
#include <QtNetwork>
#include "../../src/SmtpMime"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // This is a first demo application of the SmtpClient for Qt project


    // First we need to create an SmtpClient object
    // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

    qDebug() << QSslSocket::sslLibraryBuildVersionString();

    SmtpClient smtp("11.91.80.55", 25, SmtpClient::TlsConnection);
    smtp.setAuthMethod(SmtpClient::AuthLogin);
    // We need to set the username (your email address) and password
    // for smtp authentification.

//    smtp.setName("cdpc011.corp.ats.net");
    smtp.setUser("xxx-main\\xxx_sys_linux");
    smtp.setPassword("xxx");

    // Now we create a MimeMessage object. This is the email.

    MimeMessage message;

    EmailAddress sender("xxx_shasys@cn.xxx.net", "xxx_shasys");
    message.setSender(&sender);

    EmailAddress to("leon.li@xxx.com", "Leon Li");
    message.addRecipient(&to);

    message.setSubject("SmtpClient for Qt - TLS Demo");

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText("Hi,\nThis is a simple email message.\n");

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail

    if (!smtp.connectToHost()) {
        qDebug() << "Failed to connect to host!" << endl;
        return -1;
    }

    if (!smtp.login()) {
        qDebug() << "Failed to login!" << endl;
        return -2;
    }

    if (!smtp.sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
        return -3;
    }

    smtp.quit();
    qDebug() << "Done!";
}

