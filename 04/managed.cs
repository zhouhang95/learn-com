using System.Runtime.InteropServices;

[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("bc429c01-9f13-4b29-b3f2-b90be62578e5")]
interface IHen {
    [PreserveSig] void Cluck();
}

[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("c7c12279-b5c7-4d09-9a7b-5e932c4ee896")]
interface IHen2 {
    [PreserveSig] void Cluck();
    [PreserveSig] void Forage();
}

class Application {
    static void Main() {
        IHen hen = CreateHen();
        hen.Cluck();
        IHen2 hen2 = (IHen2)hen;
        hen2.Forage();
    }
    [DllImport("Library.dll", PreserveSig = false)]
    static extern IHen CreateHen();
}