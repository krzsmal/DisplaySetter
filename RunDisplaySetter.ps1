Register-WmiEvent -Namespace root\cimv2 -Query "SELECT * FROM __InstanceCreationEvent WITHIN 2 WHERE TargetInstance ISA 'Win32_PnPEntity'" -Action {
    $device = $Event.SourceEventArgs.NewEvent.TargetInstance
    if ($device.Description -like "*Monitor*") {
        Start-Process "DisplaySetter.exe"
    }
}

Wait-Event
