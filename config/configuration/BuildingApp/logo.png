package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"os/exec"
	"strings"
	"time"
)

const version = "v4.0.0"

// Colors
var colors = []string{
	"\033[31m", "\033[32m", "\033[33m",
	"\033[34m", "\033[35m", "\033[36m",
}

const logo = `
███╗   ██╗███╗   ███╗ █████╗ ██████╗ 
████╗  ██║████╗ ████║██╔══██╗██╔══██╗
██╔██╗ ██║██╔████╔██║███████║██████╔╝
██║╚██╗██║██║╚██╔╝██║██╔══██║██╔═══╝ 
██║ ╚████║██║ ╚═╝ ██║██║  ██║██║     
╚═╝  ╚═══╝╚═╝     ╚═╝╚═╝  ╚═╝╚═╝     

██████╗ ██╗██╗      ██████╗ ████████╗
██╔══██╗██║██║     ██╔═══██╗╚══██╔══╝
██████╔╝██║██║     ██║   ██║   ██║   
██╔═══╝ ██║██║     ██║   ██║   ██║   
██║     ██║███████╗╚██████╔╝   ██║   
╚═╝     ╚═╝╚══════╝ ╚═════╝    ╚═╝   

        🛰  NmapPilot | @ghaithrb
`
func printLogo() {
	rand.Seed(time.Now().UnixNano())
	color := colors[rand.Intn(len(colors))]
	fmt.Println(color + logo + "\033[0m")
	fmt.Printf("Version: %s | @ghaithrb\n\n", version)
}

func runNmap(options string, target string) string {
	cmd := exec.Command("bash", "-c",
		fmt.Sprintf("nmap %s %s", options, target))

	output, _ := cmd.CombinedOutput()
	fmt.Println(string(output))
	return string(output)
}

func saveOutput(content string) {
	filename := fmt.Sprintf("scan-%s.txt",
		time.Now().Format("20060102-150405"))

	os.WriteFile(filename, []byte(content), 0644)
	fmt.Println("✅ Saved to:", filename)
}

func main() {

	printLogo()

	reader := bufio.NewReader(os.Stdin)

	scans := map[string]struct {
		name    string
		desc    string
		example string
		option  string
	}{
		"1":  {"Ping Scan", "Discover live hosts", "Ex: 192.168.1.0/24", "-sn"},
		"2":  {"Quick Scan", "Fast scan top 100 ports", "Ex: 192.168.1.10", "-T4 -F"},
		"3":  {"Aggressive Scan", "OS + Version + Scripts", "Ex: 10.0.0.5", "-A"},
		"4":  {"Vulnerability Scan", "Run vuln scripts", "Ex: 192.168.1.1", "--script vuln"},
		"5":  {"OS Detection", "Detect Operating System", "Ex: 10.10.10.10", "-O"},
		"6":  {"Service Version", "Detect service versions", "Ex: 192.168.1.5", "-sV"},
		"7":  {"Full Port Scan", "Scan all 65535 ports", "Ex: 192.168.1.10", "-p-"},
		"8":  {"Stealth Scan", "TCP SYN stealth scan", "Ex: 10.0.0.5", "-sS"},
		"9":  {"UDP Scan", "Scan UDP ports", "Ex: 192.168.1.5", "-sU"},
		"10": {"Firewall Evasion", "Fragment packets", "Ex: 192.168.1.10", "-f"},
		"11": {"XMAS Scan", "Advanced stealth scan", "Ex: 10.0.0.1", "-sX"},
		"12": {"NULL Scan", "No flags scan", "Ex: 192.168.1.1", "-sN"},
		"13": {"FIN Scan", "Stealth FIN scan", "Ex: 192.168.1.10", "-sF"},
		"14": {"Traceroute", "Trace network path", "Ex: 8.8.8.8", "--traceroute"},
		"15": {"Custom Ports", "Scan specific ports", "Ex: 22,80,443", "-p"},
	}

	fmt.Println("══════════════════════════════")
	fmt.Println("Available Scan Options (1-15)")
	fmt.Println("══════════════════════════════")

	for i := 1; i <= 15; i++ {
		key := fmt.Sprintf("%d", i)
		scan := scans[key]
		fmt.Printf("[%s] %-20s → %s\n", key, scan.name, scan.desc)
	}

	fmt.Print("\nSelect option (1-15): ")
	choice, _ := reader.ReadString('\n')
	choice = strings.TrimSpace(choice)

	scan, exists := scans[choice]
	if !exists {
		fmt.Println("❌ Invalid option")
		return
	}

	fmt.Println("\n🔎", scan.name)
	fmt.Println("Description:", scan.desc)
	fmt.Println("Example:", scan.example)
	fmt.Println()

	fmt.Print("Enter target: ")
	target, _ := reader.ReadString('\n')
	target = strings.TrimSpace(target)

	options := scan.option

	if choice == "15" {
		fmt.Print("Enter ports: ")
		ports, _ := reader.ReadString('\n')
		options = "-p " + strings.TrimSpace(ports)
	}

	fmt.Println("\n🚀 Running scan...\n")
	result := runNmap(options, target)

	fmt.Print("\nSave result? (y/n): ")
	save, _ := reader.ReadString('\n')
	if strings.TrimSpace(save) == "y" {
		saveOutput(result)
	}

	fmt.Println("\n✅ Scan Completed Successfully.")
}
