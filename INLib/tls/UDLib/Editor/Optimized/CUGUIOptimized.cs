using UnityEngine;
using UnityEditor;
using UnityEngine.UI;
 namespace UDLib.Editor
{
    public class CUGUIOptimized
    {
        /// <summary>
        /// �󲿷�Text����Ҫ������Ӧ�¼�������RaycastTarget���Բ��ù�ѡ��
        /// </summary>
        /// <param name="menuCommand"></param>
        //[MenuItem("GameObject/UI/Optimized/Text", false)]
        static public GameObject CreatText(MenuCommand menuCommand)
        {
            EditorApplication.ExecuteMenuItem("GameObject/UI/Text");
            GameObject go = Selection.activeGameObject;
            GameObjectUtility.SetParentAndAlign(go, menuCommand.context as GameObject);
            go.GetComponent<Text>().raycastTarget = false;
            return go;
        }

        /// <summary>
        /// �󲿷�Image����Ҫ������Ӧ�¼�������RaycastTarget���Բ��ù�ѡ��
        /// </summary>
        /// <param name="menuCommand"></param>
        [MenuItem("GameObject/UI/Optimized/Image", false)]
        static public GameObject CreatImage(MenuCommand menuCommand)
        {
            EditorApplication.ExecuteMenuItem("GameObject/UI/Image");
            GameObject go = Selection.activeGameObject;
            GameObjectUtility.SetParentAndAlign(go, menuCommand.context as GameObject);
            go.GetComponent<Image>().raycastTarget = false;
            return go;
        }

        /// <summary>
        /// buttonһ����Ҫ������Ӧ�¼�������RaycastTarget��Ĭ�Ϲ�ѡ��
        /// </summary>
        /// <param name="menuCommand"></param>
        //[MenuItem("GameObject/UI/Optimized/Button", false)]
        static public GameObject CreatButton(MenuCommand menuCommand)
        {
            EditorApplication.ExecuteMenuItem("GameObject/UI/Button");
            GameObject go = Selection.activeGameObject;
            GameObjectUtility.SetParentAndAlign(go, menuCommand.context as GameObject);
            return go;
        }
    }
}
