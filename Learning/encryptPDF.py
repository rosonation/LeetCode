import PyPDF2

pdfFileObj = open('/Users/tony/Downloads/automate_online-materials/meetingminutes.pdf', 'rb')
pdfReader = PyPDF2.PdfFileReader(pdfFileObj)
pdfWriter = PyPDF2.PdfFileWriter()

for pageNum in range(pdfReader.numPages):
    pdfWriter.addPage(pdfReader.getPage(pageNum))

pdfWriter.encrypt('swordfish')
resultPdfFile = open('/Users/tony/Tony/PDF/encryptminutes.pdf', 'wb')
print("Write PDF to file:", "/Users/tony/Tony/PDF/encryptminutes.pdf")
pdfWriter.write(resultPdfFile)
resultPdfFile.close()
