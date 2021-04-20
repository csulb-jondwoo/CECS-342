using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Linq;

namespace Lab4
{
    class Program
    {
        static IEnumerable<string> EnumerateFilesRecursively(string path)
        {
            foreach (string d in Directory.EnumerateDirectories(path))
            {
                foreach (string f in Directory.EnumerateFiles(d))
                {
                    yield return f;
                }
                EnumerateFilesRecursively(d);
            }
        }
        static string FormatByteSize(long byteSize)
        {
            // B KB
            if (byteSize >= 0 && byteSize <= (long)Math.Pow(10, 3))
            {
                long newByteSize = byteSize / 1000;
                if (newByteSize >= 1000)
                {
                    float f = newByteSize / 1000;
                    float truncated = (float)(Math.Truncate((double)f * 100.0) / 100.0);

                    return (f.ToString() + " B");
                }
                else
                    return (newByteSize.ToString() + " KB");
            }
            // KB MB
            else if (byteSize > (long)Math.Pow(10, 3) && byteSize <= (long)Math.Pow(10, 6))
            {
                long newByteSize = byteSize / (long)Math.Pow(10, 3);
                if (newByteSize >= 1000)
                {
                    float f = newByteSize / 1000;
                    float truncated = (float)(Math.Truncate((double)f * 100.0) / 100.0);
                    return (f.ToString() + " KB");
                }
                else
                    return (newByteSize.ToString() + " MB");
            }
            // MB GB
            else if (byteSize > (long)Math.Pow(10, 6) && byteSize <= (long)Math.Pow(10, 9))
            {
                long newByteSize = byteSize / (long)Math.Pow(10, 6);
                if (newByteSize >= 1000)
                {
                    float f = newByteSize / 1000;
                    float truncated = (float)(Math.Truncate((double)f * 100.0) / 100.0);
                    return (f.ToString() + " MB");
                }
                else
                    return (newByteSize.ToString() + " GB");
            }
            // GB TB
            else if (byteSize > (long)Math.Pow(10, 9) && byteSize <= (long)Math.Pow(10, 12))
            {
                long newByteSize = byteSize / (long)Math.Pow(10, 9);
                if (newByteSize >= 1000)
                {
                    float f = newByteSize / 1000;
                    float truncated = (float)(Math.Truncate((double)f * 100.0) / 100.0);
                    return (f.ToString() + " GB");
                }
                else
                    return (newByteSize.ToString() + " TB");
            }

            return "";
        }
        static XDocument CreateReport(string path)
        {
            XDocument report = new XDocument(new XElement("html",
                                                new XElement("head",
                                                    new XElement("body",
                                                        new XElement("td", getFileInfo(path))))));
            return report;
        }
        public static XElement getFileInfo(string path)
        {
            IEnumerable<string> files = EnumerateFilesRecursively(path);

            var query = from f in files
                        group f by Path.GetExtension(f).ToLower() into fileGroup
                        let size = fileGroup.Select(file => new FileInfo(file).Length).Sum()
                        orderby size descending
                        select new
                        {
                            Type = fileGroup.Key,
                            Count = fileGroup.Count(),
                            Size = FormatByteSize(fileGroup.Select(file => new FileInfo(file).Length).Sum())
                        };

            XElement table = new XElement("table",
                new XAttribute("style", "width : 50%"),
                new XAttribute("border", 1),
                new XElement("thead",
                    new XElement("tr",
                        new XElement("th", "filetype"),
                        new XElement("th", "count"),
                        new XElement("th", "size")),
                new XElement("tbody",
                    new XElement("tr", from value in query
                                       select
            new XElement("tr",
                new XElement("td", value.Type),
                new XElement("td", value.Count),
                new XElement("td", value.Size))))));

            return table;
        }
        static void Main(string[] args)
        {
            string inputFolder, outputFolder;

            Console.WriteLine("Enter input folder from your user directory:");
            inputFolder = "C:\\Users\\Jon\\" + Console.ReadLine();

            XDocument report = CreateReport(inputFolder);

            Console.WriteLine("Enter a name for the output file:");
            outputFolder = "C:\\Users\\Jon\\Desktop\\" + Console.ReadLine();
            report.Save(outputFolder);
        }
    }
}
